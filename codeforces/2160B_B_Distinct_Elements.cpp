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
        vector<long long> b(n + 1, 0); // 1-indexed read, b[0] = 0
        for (int i = 1; i <= n; ++i)
            cin >> b[i];

        vector<int> a(n + 1, 0); // 1-indexed result
        int nextVal = 1;         // next new label (start from 1)
        for (int i = 1; i <= n; ++i)
        {
            long long g = b[i] - b[i - 1]; // contribution of position i
            // prev = i - g (should be between 0 and i-1)
            long long prev = i - g;
            if (prev == 0)
            {
                // new distinct value never seen before
                a[i] = nextVal++;
            }
            else
            {
                // must equal value at position prev
                a[i] = a[(int)prev];
            }
        }

        for (int i = 1; i <= n; ++i)
        {
            if (i > 1)
                cout << ' ';
            cout << a[i];
        }
        cout << '\n';
    }
    return 0;
}
