class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> v;
        int p=(1<<n); //2^N
        for(int i=0; i<p; i++){
            v.push_back(i^(i >> 1)); //(i ^ (i >> 1))
        }
        return v;
    }
};