#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<int, bool> memo; // cache for states
    int maxInt, target;

    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        maxInt = maxChoosableInteger;
        target = desiredTotal;

        // Case 1: if total we want is 0 or less, first player trivially wins
        if (target <= 0) return true;

        // Case 2: if sum of all numbers < target, impossible to reach target
        int sumAll = (maxInt * (maxInt + 1)) / 2;
        if (sumAll < target) return false;

        // start recursion with empty mask (no numbers used) and 0 sum
        return canWinHelper(0, 0);
    }

    bool canWinHelper(int usedMask, int currentSum) {
        // If we already solved this state, return cached answer
        if (memo.count(usedMask)) return memo[usedMask];

        // Try all numbers from 1 to maxInt
        for (int i = 1; i <= maxInt; i++) {
            int bit = 1 << (i - 1); // map number i to bit position (i-1)

            // Skip if number already used
            if (usedMask & bit) continue;

            // If picking i reaches target OR forces opponent to lose
            if (currentSum + i >= target || !canWinHelper(usedMask | bit, currentSum + i)) {
                return memo[usedMask] = true;
            }
        }

        // If no winning move found, current player loses
        return memo[usedMask] = false;
    }
};

int main() {
    Solution sol;

    cout << boolalpha;
    cout << sol.canIWin(10, 11) << endl; // true
    cout << sol.canIWin(10, 40) << endl; // false
    cout << sol.canIWin(15, 100) << endl; // true
    cout << sol.canIWin(5, 6) << endl;   // true
    cout << sol.canIWin(5, 50) << endl;  // false

    return 0;
}
