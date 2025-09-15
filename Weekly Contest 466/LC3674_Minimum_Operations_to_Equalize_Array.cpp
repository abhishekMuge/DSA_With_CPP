class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        int num=nums[0];
        for(auto it:nums){
            if(it==num)cnt++;
        }
        if(cnt==n)return 0;
        return 1;
    }
};