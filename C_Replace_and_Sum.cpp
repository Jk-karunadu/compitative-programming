#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, q;
        cin >> n >> q;
        vector<int> a(n);
        vector<int> b(n);

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
            if (b[i] > a[i])
            {
                a[i] = b[i];
            }
        }

        for (int i = n - 1; i > 0; i--)
        {
            if (a[i] > a[i - 1])
            {
                a[i - 1] = a[i];
            }
        }

        vector<long long> prefix_sum(n);
        prefix_sum[0] = a[0];
        for (int i = 1; i < n; i++)
        {
            prefix_sum[i] = prefix_sum[i - 1] + a[i];
        }
        while (q--)
        {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            long long result = prefix_sum[r];
            if (l > 0)
            {
                result -= prefix_sum[l - 1];
            }
            cout << result <<" ";
        }
        cout << endl;
    }
}