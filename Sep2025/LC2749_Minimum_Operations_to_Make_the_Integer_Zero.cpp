class Solution {
public:
    int makeTheIntegerZero(int n1, int n2) {
        for (int op = 1; op <= 60; op++) {
            long long rem = 1LL * n1 - 1LL * op * n2;
            if (rem < op) continue;
            int pop = __builtin_popcountll(rem);
            if (pop <= op && op <= rem) return op;
        }
        return -1;
    }
};