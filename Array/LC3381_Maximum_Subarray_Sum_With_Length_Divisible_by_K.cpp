#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

class solution
{
public:
    long long maxSubarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<long long> minPrefix(k, LLONG_MAX);

        long long prefix = 0;
        long long ans = LLONG_MIN;

        // prefix index 0 has modulo 0 with sum = 0
        minPrefix[0] = 0;

        for (int i = 0; i < n; i++)
        {
            prefix += nums[i];
            int mod = ((i + 1) % k + k) % k;

            // If we have seen a prefix with same modulo
            if (minPrefix[mod] != LLONG_MAX)
            {
                ans = max(ans, prefix - minPrefix[mod]);
            }

            // Update the smallest prefix for this modulo
            minPrefix[mod] = min(minPrefix[mod], prefix);
        }

        return ans;
    }
};
