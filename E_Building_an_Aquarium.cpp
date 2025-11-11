#include <bits/stdc++.h>
using namespace std;

bool is_possible(long long h, vector<long long> &vec, long long x)
{
    long long sum = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        if (h > vec[i])
        {
            sum = sum + (h - vec[i]);
        }
        if (sum > x)
        {
            return false;
        }
    }
    return true; 
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        long long x;

        cin >> n >> x;

        vector<long long> vec(n);
        long long mx = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> vec[i];
            mx = max(mx, vec[i]);
        }

        long long l = 0;
        long long h = mx + x;
        long long ans = 0; 

        while (l <= h)
        {
            long long mid = l + (h - l) / 2;

            if (is_possible(mid, vec, x))
            {
                ans = mid;
                l = mid + 1;
            }
            else
            {
                h = mid - 1;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}