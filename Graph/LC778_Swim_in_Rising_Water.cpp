class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> visited(n, vector<int>(n, 0));

        // Min-heap: {time, x, y}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({grid[0][0], 0, 0});
        visited[0][0] = 1;

        // Directions: up, down, left, right
        vector<pair<int,int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        while (!pq.empty()) {
            auto cur = pq.top(); pq.pop();
            int time = cur[0], x = cur[1], y = cur[2];

            // If we reach destination, return time
            if (x == n - 1 && y == n - 1) return time;

            for (auto [dx, dy] : dirs) {
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && ny >= 0 && nx < n && ny < n && !visited[nx][ny]) {
                    visited[nx][ny] = 1;
                    int new_time = max(time, grid[nx][ny]);
                    pq.push({new_time, nx, ny});
                }
            }
        }
        return -1; // should never happen
    }
};