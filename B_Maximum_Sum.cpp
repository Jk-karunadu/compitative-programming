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
        int n, k;
        cin >> n >> k;
        vector<long long> vec(n);

        for (int i = 0; i < n; i++)
        {
            cin >> vec[i];
        }

        sort(vec.begin(), vec.end());

        vector<long long> prefix_sum(n + 1);
        prefix_sum[0] = 0;
        for (int i = 0; i < n; i++) {
            prefix_sum[i + 1] = prefix_sum[i] + vec[i];
        }

        long long ans = 0; 

        for (int i = 0; i <= k; i++) {
            
            int removals_from_right = k - i;
            int l = 2 * i; 
            int h = n - 1 - removals_from_right; 

            if (l > h) {
                ans = max(ans, 0LL);
                continue;
            }

            long long current_sum = prefix_sum[h + 1] - prefix_sum[l];
            ans = max(ans, current_sum);
        }

        cout << ans << "\n";
    }
    return 0;
}