#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        unordered_map<long long, int> m;

        for (int i = 0; i < n; i++)
        {
            long long x;
            cin >> x;
            m[x]++;
        }

        int mx = 0;
        for (auto &p : m)
        {
            mx = max(mx, p.second);
        }

        if (mx == n)
        {
            cout << 0 << "\n"; 
            continue;
        }

        int ops = 0;
        int cur = mx;

        while (cur < n)
        {
           
            ops++; 

          
            int add = min(cur, n - cur);
            ops += add;
            cur += add;
        }

        cout << ops << "\n";
    }

    return 0;
}
