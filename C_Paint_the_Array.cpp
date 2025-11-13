#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<long long> a(n);
        
        long long gcd1 = 0; 
        long long gcd2 = 0; 

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (i % 2 == 0)
            {
                gcd1 = __gcd(gcd1, a[i]);
            }
            else
            {
                gcd2 = __gcd(gcd2, a[i]);
            }
        }

        bool can_use_gcd1 = true; 
        bool can_use_gcd2 = true; 

        for (int i = 1; i < n; i = i + 2)
        {
            if (a[i] % gcd1 == 0)
            {
                can_use_gcd1 = false; 
                break;
            }
        }

        for (int i = 0; i < n; i = i + 2)
        {
            if (a[i] % gcd2 == 0)
            {
                can_use_gcd2 = false; 
                break;
            }
        }

        if (can_use_gcd1) {
            cout << gcd1 << "\n";
        } else if (can_use_gcd2) {
            cout << gcd2 << "\n";
        } else {
            cout << 0 << "\n";
        }
    }
    return 0; 
}