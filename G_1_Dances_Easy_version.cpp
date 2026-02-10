#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> a, vector<int> b, int ops)
{
    for (int i = 0; i < ops; i++)
    {
        a.pop_back();
        b.pop_back();
    }

    reverse(b.begin(), b.end());
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] >= b[i])
            return false;
    }
    return true;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vector<int> a(n);
        a[0] = 1;
        for (int i = 1; i < n; i++)
            cin >> a[i];
        vector<int> b(n);
        for (int i = 0; i < n; i++)
            cin >> b[i];

        sort(a.begin(), a.end());
        sort(b.begin(), b.end(), greater<int>());
        int l = 0;
        int h = n;

        while (l < h)
        {
            int m = l + (h - l) / 2;
            if (check(a, b, m))
            {
                h = m;
            }
            else
            {
                l = m + 1;
            }
        }

        cout << l << endl;
    }
}