#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t))
        return 0;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> cnt(102, 0);
        for (int i = 0; i < n; ++i)
        {
            int x;
            cin >> x;
            if (x >= 0 && x <= 101)
                cnt[x]++;
        }

        int mex = 0;
        while (mex < (int)cnt.size() && cnt[mex] > 0)
            ++mex;
        cout << mex << '\n';
    }
    return 0;
}
