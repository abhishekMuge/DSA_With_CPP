#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// DP version
class Solution
{
public:
    int maxSumDivThree(vector<int> &nums)
    {
        vector<int> dp(3, INT_MIN);
        dp[0] = 0;

        for (int x : nums)
        {
            vector<int> temp(dp); // snapshot

            for (int r = 0; r < 3; r++)
            {
                int newR = (r + x % 3) % 3;
                temp[newR] = max(dp[newR], dp[r] + x);
            }

            dp = temp;
        }

        return dp[0];
    }
};

// compute mod 0, 1 , 2 state solution
class Solution1
{
public:
    int maxSumDivThree(vector<int> &nums)
    {
        long long sum = 0;
        vector<int> rem1, rem2;

        for (int x : nums)
        {
            sum += x;
            if (x % 3 == 1)
                rem1.push_back(x);
            else if (x % 3 == 2)
                rem2.push_back(x);
        }

        sort(rem1.begin(), rem1.end());
        sort(rem2.begin(), rem2.end());

        if (sum % 3 == 0)
            return sum;

        long long ans = 0;

        if (sum % 3 == 1)
        {
            long long remove1 = rem1.size() >= 1 ? rem1[0] : LLONG_MAX;
            long long remove2 = rem2.size() >= 2 ? (long long)rem2[0] + rem2[1] : LLONG_MAX;

            ans = sum - min(remove1, remove2);
        }
        else
        { // sum % 3 == 2
            long long remove1 = rem2.size() >= 1 ? rem2[0] : LLONG_MAX;
            long long remove2 = rem1.size() >= 2 ? (long long)rem1[0] + rem1[1] : LLONG_MAX;

            ans = sum - min(remove1, remove2);
        }

        return ans;
    }
};
