class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& sf) {
        sort(sf.begin(), sf.end());
        int n = sf.size(), res = max(sf[0] - bottom, top - sf[n-1]);
        for(int i = 1; i < n; i++) {
            res = max(res, sf[i] - sf[i - 1] - 1);
        }
        return res;
    }
};