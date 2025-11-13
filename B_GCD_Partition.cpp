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

        long long ans = 1;
        long long total_sum = prefix[n]; // The total sum

      
        for (int i = 1; i < n; i++)
        {
            long long sum_left = prefix[i];
            long long sum_right = total_sum - prefix[i];
            ans = max(ans, __gcd(sum_left, sum_right));
        }

        cout << ans << "\n"; // Add newline
    }
    return 0; // Added return 0
}