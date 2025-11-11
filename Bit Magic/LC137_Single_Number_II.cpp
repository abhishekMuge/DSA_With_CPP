class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0;
        for(int n: nums){
            ones = (n ^ ones) & ~twos;
            twos = (n ^ twos) & ~ones;
        }
        return ones;
    }
};