#include <iostream>

class Solution
{
public:
    static constexpr long long MOD = 1000000007LL;

    long long fastPow(long long base, long long exp)
    {
        long long result = 1;
        base %= MOD;
        while (exp > 0)
        {
            if (exp & 1)
                result = (result * base) % MOD;
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return result;
    }

    // make n a 64-bit value
    int countGoodNumbers(long long n)
    {
        long long even_positions = (n + 1) / 2; // indices 0,2,4,...
        long long odd_positions = n / 2;        // indices 1,3,5,...

        long long ways_even = fastPow(5, even_positions);
        long long ways_odd = fastPow(4, odd_positions);

        return static_cast<int>((ways_even * ways_odd) % MOD);
    }
};
