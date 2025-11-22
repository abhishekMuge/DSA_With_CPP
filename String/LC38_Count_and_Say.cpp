#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    string CountAndSay(int n)
    {
        // start Logic Here
        string s = "1";
        for (int i = 0; i < n - 1; i++)
        {
            string temp = "";
            char curr = s[0];
            int count = 0;

            for (auto it : s)
            {
                if (it == curr)
                {
                    count++;
                }
                else
                {
                    temp += to_string(count) + curr;
                    curr = it;
                    count = 1;
                }
            }
            temp += to_string(count) + curr;
            s = temp;
        }
        return s;
    }
};

int main()
{
    Solution s;
    cout << s.CountAndSay(10) << endl;
}