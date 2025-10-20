class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int cnt = 0, prev = INT_MIN;
        for(int num : nums){
            int cur = min(max(num - k, prev + 1), num + k);
            if(cur > prev) {
                cnt++;
                prev = cur;
            }
        }
        return cnt;
    }
};