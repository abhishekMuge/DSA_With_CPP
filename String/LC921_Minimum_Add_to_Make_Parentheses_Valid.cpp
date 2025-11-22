#include <iostream>
#include <string>
class Solution
{
public:
    int minAddToMakeValid(std::string s)
    {
        int left = 0, right = 0;
        for (char ch : s)
        {
            if (ch == '(')
                right++;
            else if (right > 0)
                right--;
            else
                left++;
        }
        return right + left;
    }
};

int main()
{
    Solution s;
    std::cout << "res: " << s.minAddToMakeValid("()))") << std::endl;
}