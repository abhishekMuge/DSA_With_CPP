class Solution
{
public:
    int smallestRepunitDivByK(int k)
    {
        // Step 1: Quick check for impossible cases
        if (k % 2 == 0 || k % 5 == 0)
            return -1;

        int remainder = 0;

        // Step 2: Iterate at most k times (Pigeonhole principle)
        for (int length = 1; length <= k; length++)
        {
            remainder = (remainder * 10 + 1) % k;

            // If remainder becomes 0, the number is divisible
            if (remainder == 0)
                return length;
        }

        return -1; // Not found
    }
};