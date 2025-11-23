#include <iostream>
#include <string>
#include <vector>

using namespace std;

class solution
{
public:
    int substr(string heystack, string needle)
    {
        if (needle.empty())
            return 0;

        // build LPS Array
        vector<int> lps(needle.size(), 0);
        buildLongestPrefixSuffix(needle, lps);

        // KMP Search Logic
        int i = 0, j = 0;
        while (i < heystack.size())
        {
            if (heystack[i] == needle[i])
            {
                i++;
                j++;
                if (j == needle.size())
                    return i - j;
            }
            else
            {
                if (j != 0)
                {
                    j = lps[j - 1];
                }
                else
                {
                    i++;
                }
            }
        }
        return -1;
    }

    void buildLongestPrefixSuffix(const string &pattern, vector<int> &lps)
    {
        int len = 0;
        int i = 1;

        while (i < pattern.size())
        {
            if (pattern[i] == pattern[len])
            {
                len++;
                lps[i] = len;
                i++;
            }
            else
            {
                if (len != 0)
                {
                    len = lps[len - 1];
                }
                else
                {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }
};
