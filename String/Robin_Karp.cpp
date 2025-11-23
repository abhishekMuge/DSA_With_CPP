#include <iostream>
#include <string>
using namespace std;
class Solution
{
public:
    int strStr(string text, string pattern)
    {
        int n = text.size();
        int m = pattern.size();
        if (m == 0)
            return 0;
        if (n < m)
            return -1;

        const int base = 256;
        const long long mod = 1e9 + 7;

        long long patHash = 0, textHash = 0, power = 1;

        // Precompute base^(m-1)
        for (int i = 0; i < m - 1; i++)
            power = (power * base) % mod;

        // Compute hash of pattern and first window
        for (int i = 0; i < m; i++)
        {
            patHash = (patHash * base + pattern[i]) % mod;
            textHash = (textHash * base + text[i]) % mod;
        }

        // Slide window over text
        for (int i = 0; i <= n - m; i++)
        {
            if (patHash == textHash)
            {
                // Verify match (avoid collision)
                if (text.substr(i, m) == pattern)
                    return i;
            }

            // Move window forward (rolling hash)
            if (i < n - m)
            {
                textHash = (textHash - text[i] * power) % mod;
                if (textHash < 0)
                    textHash += mod;

                textHash = (textHash * base + text[i + 1]) % mod;
            }
        }

        return -1;
    }
};

// TC - O(n) -
// Worst case - O(n*m) if many hash collisions and substring compare triggers often (rare with a good mod).