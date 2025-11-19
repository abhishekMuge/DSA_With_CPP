class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();

        
        for (int bit = 0; bit < 32; bit++) {
            long long ones = 0;

            
            for (int x : nums) {
                if (x & (1 << bit)) ones++;
            }

            long long zeros = n - ones;

            
            ans += ones * zeros;
        }

        return ans;
    }
};