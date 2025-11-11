#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Add fast I/O
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<long long> vec(n);
        vector<long long> prefix(n + 1);
        prefix[0] = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> vec[i];
            prefix[i + 1] = prefix[i] + vec[i];
        }

        
        long long ans = 0;

        
        for (int k = 1; k <= n; k++)
        {
           
            if (n % k != 0) {
                continue;
            }

           
            long long mn = LLONG_MAX;
            long long mx = LLONG_MIN;

           
            for (int i = k; i <= n; i = i + k)
            {
                long long current_sum = prefix[i] - prefix[i - k];
                mn = min(mn, current_sum);
                mx = max(mx, current_sum);
            }

            
            ans = max(ans, mx - mn);
        }

        cout << ans << "\n"; 
    }
    return 0; 
}