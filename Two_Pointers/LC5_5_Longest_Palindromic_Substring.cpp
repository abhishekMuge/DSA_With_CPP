class Solution {
public:
    string ans = "";
    void expand(string &s , int left ,int right)
    {
        while(left >= 0 &&  right < s.size())
        {
            if(s[left] != s[right])
                break;
            left--,right++;
        }
        if(ans.size() < right - left )
            ans = s.substr(left + 1 , right - left - 1);
    }
    string longestPalindrome(string s) {
        for(int i = 0 ; i < s.size() ; i++)
        {
            expand(s , i , i);
            expand(s , i , i+1);
        }
        return ans;
    }
};


/*
finds the longest palindromic substring by iterating through each character of the input string s as a potential center of a palindrome. For each character, it calls an expand function twice: once for odd-length palindromes (centered at i) and once for even-length palindromes (centered between i and i+1). The expand function then grows outwards from the center(s) to find the longest palindrome for that center and updates the ans variable if a longer palindrome is found.

TC(O(N^2))
*/