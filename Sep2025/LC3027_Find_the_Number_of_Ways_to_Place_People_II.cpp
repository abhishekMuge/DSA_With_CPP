class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();

        auto compare = [](vector<int>& A, vector<int>& B){
            if(A[0] == B[0]){
                //if my both x are same will sort points in descending with y value
                return A[1] > B[1];
            }
            return A[0] < B[0];
        };
        sort(begin(points), end(points), compare);

        int res = 0;
        for(int i = 0; i < n; i++) {
            int x1 = points[i][0];
            int y1 = points[i][1];

            int maxY = INT_MIN;
            for(int j = i+1; j < n; j++) {
                int x2 = points[j][0];
                int y2 = points[j][1];

                if(y2 > y1) continue;

                if(y2 > maxY) {
                    res++;
                    maxY = y2;
                }
            }
        }
        return res;
    }
};