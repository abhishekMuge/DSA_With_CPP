#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        // Sort by end ascending. If ends equal, sort by start descending.
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){
            if (a[1] == b[1]) return a[0] > b[0];
            return a[1] < b[1];
        });

        int ans = 0;
        // last1 = largest chosen number so far
        // last2 = second largest chosen number so far
        int last1 = INT_MIN, last2 = INT_MIN;

        for (auto &iv : intervals) {
            int a = iv[0], b = iv[1];
            if (last1 < a) {
                // no chosen numbers in [a,b] -> need two numbers
                ans += 2;
                last2 = b - 1;
                last1 = b;
            } else if (last2 < a) {
                // exactly one chosen number in [a,b] -> need one more
                ans += 1;
                // shift and add b as the newest (largest) chosen
                last2 = last1;
                last1 = b;
            }
            // else (last2 >= a): already have two numbers inside interval
        }

        return ans;
    }
};