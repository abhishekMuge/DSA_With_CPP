#include <vector>

using namespace std;

class Solution
{
public:
    vector<bool> prefixesDivBy5(vector<int> &nums)
    {
        vector<bool> answer(nums.size());
        int rem = 0; // remainder % 5

        for (int i = 0; i < nums.size(); i++)
        {
            rem = (rem * 2 + nums[i]) % 5;
            answer[i] = (rem == 0);
        }

        return answer;
    }
};

/*
When reading binary digits from left to right, adding a new bit works like:

new_value = old_value * 2 + bit


But instead of storing the whole number, we only track its remainder mod 5, because:

(new_value % 5) = (old_remainder * 2 + bit) % 5


So for each bit nums[i]:

rem = (rem * 2 + nums[i]) % 5


If rem == 0, then the prefix number is divisible by 5.

This keeps numbers small and lets us check divisibility efficiently.
*/