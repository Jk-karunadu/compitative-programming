#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, p, e;
        cin >> n >> k >> p >> e;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        p--; // convert to 0-index

        int sum = 0;

        for (int i = p; i < n; i++)
        {
            sum = sum + a[i];
        }

        int r = n - k - (n - (p + 1));

        for (int i = 0; i < r && i < n; i++)
        {
            sum = sum + a[i];
        }

        if (k < p + 1)
        {
            int i = 0;
            while (i != (p + 1) - k)
            {
                e = e - a[i];
                i++;
                if (e < 0) break;
            }
            if (e >= a[p]) e = e - a[p];
            else e = -1;
        }
        else
        {
            if (e >= a[p]) e = e - a[p];
            else e = -1;
        }

        int count = 0;

        if (e >= 0) count = 1;

        while (e >= (sum - a[p]))
        {
            e = e - (sum - a[p]);
            count++;
        }

        if (e < 0) count = 0;

        cout << count << endl;
    }
}