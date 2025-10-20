class Solution {
public:

    int longestSubarray(vector<int>& a) {
        int ans=2,curr=2;

        int n=a.size();

        for(int i=2;i<n;i++){
            if(a[i]==a[i-1] + a[i-2]) curr++;
            else curr=2;
            ans  =max(ans,curr);
        }
        return ans;
    }
};
