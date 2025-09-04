class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++) {
            int l = 0, r = n - 1;
            while (l <= r) {
                if (l == r) {
                    // middle element, just toggle once
                    grid[i][l] ^= 1;
                } else {
                    grid[i][l] ^= 1;
                    grid[i][r] ^= 1;
                    swap(grid[i][l], grid[i][r]);
                }
                l++;
                r--;
            }
        }
        return grid;
    }
};