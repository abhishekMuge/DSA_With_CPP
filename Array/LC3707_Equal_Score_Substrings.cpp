class Solution {
public:
    bool scoreBalance(string s) {
        int n = s.size();
        vector<int> prefix(n),suffix(n);
        prefix[0]=s[0]-'a'+1;
        suffix[n-1]=s[n-1]-'a'+1;
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+s[i]-'a'+1;
        }
        for(int i=n-2;i>=0;i--){
            suffix[i]=suffix[i+1]+s[i]-'a'+1;
        }

        for(int i=0;i<n-1;i++){
            if(prefix[i]==suffix[i+1]) return true;
        }

        return false;
    }
};