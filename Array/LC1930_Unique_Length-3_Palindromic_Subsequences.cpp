class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();

        vector<int> first(26, -1), last(26, -1);

        // Step 1: record first and last occurrences
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            if (first[c] == -1) first[c] = i;
            last[c] = i;
        }

        // Step 2: prefix frequency 2D table
        vector<vector<int>> prefix(n + 1, vector<int>(26, 0));

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i];
            prefix[i + 1][s[i] - 'a']++;
        }

        int result = 0;

        // Step 3: for each character, check possible middle chars
        for (int x = 0; x < 26; x++) {
            if (first[x] == -1 || first[x] == last[x]) continue;

            int L = first[x], R = last[x];

            for (int mid = 0; mid < 26; mid++) {
                // check if mid char occurs between L+1 ... R-1
                if (prefix[R][mid] - prefix[L + 1][mid] > 0) {
                    result++;
                }
            }
        }

        return result;
    }
};