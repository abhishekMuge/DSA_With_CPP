//Hint to solve - > Count number of 1s in each consecutive-1 group. For a group with n consecutive 1s, the total contribution of it to the final answer is (n + 1) * n // 2.

class Solution {
public:
    static constexpr int P = int(1E9) + 7;

    int numSub(string s) {
        int p = 0;
        long long ans = 0;
        while (p < s.size()) {
            if (s[p] == '0') {
                ++p;
                continue;
            }
            int cnt = 0;
            while (p < s.size() && s[p] == '1') {
                ++cnt;
                ++p;
            }
            ans = ans + (1LL + (long long)cnt) * cnt / 2;
            ans = ans % P;
        }
        return ans;
    }
};