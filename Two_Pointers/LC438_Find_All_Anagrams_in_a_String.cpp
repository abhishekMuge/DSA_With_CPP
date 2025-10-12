class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(p.size() > s.size()) return {};
        vector<int> freq(26, 0), count(26, 0), res;
        int n = p.size();
        for(int i = 0; i < n ; i++) {
            freq[p[i] - 'a']++;
            count[s[i] - 'a']++;
        }
        if(freq == count) res.push_back(0);
        for(int i = n; i < s.size(); i++) {
            count[s[i-n] - 'a']--;
            count[s[i] - 'a']++;
            if(count == freq) res.push_back(i - n + 1);
        }
        return res;
    }
};