#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> p(n);
        int fidx = -1;
        int mxidx = -1;
        for (int i = 0; i < n; i++)
        {
            cin >> p[i];
            if (p[i] != n - i)
            {
                if (fidx == -1)
                    fidx = i;
            }
        }

        if (fidx == -1)
        {
            for (int i = 0; i < n; i++)
            {
                cout << p[i] << " ";
            }
            cout << endl;
            continue;
        }

        int max = -1;
        for (int i = fidx; i < n; i++)
        {
            if (p[i] > max)
            {
                max = p[i];
                mxidx = i;
            }
        }
        reverse(p.begin() + fidx, p.begin() + mxidx + 1);
        for (int i = 0; i < n; i++)
        {
            cout << p[i] << " ";
        }
        cout << endl;
    }
}