class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int xor1 = 0, xor2 = 0;
        for (int x : nums1) xor1 ^= x;
        for (int x : nums2) xor2 ^= x;

        int n = nums1.size(); // nums1 length = n
        int m = nums2.size(); // nums2 length = m

        int ans = 0;
        if (m % 2) ans ^= xor1; // because each a_i appears m times
        if (n % 2) ans ^= xor2; // because each b_j appears n times
        return ans;
    }
};