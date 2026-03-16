#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int a, b, c, n;
        cin >> a >> b >> c >> n;

        long long sum = 0;

        int mx = max({a, b, c});

        sum = abs(mx - a) + abs(mx - b) + abs(mx - c);

        int val = n - sum;

        if (val < 0)
        {
            cout << "NO" << endl;
            continue;
        }

        if (val % 3 == 0)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}