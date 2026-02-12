#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        long long k;
        cin >> n >> k;
        
        map<long long, int> m1;
        for (int i = 0; i < n; i++)
        {
            long long x;
            cin >> x;
            if (x % k != 0) {
                m1[k - (x % k)]++;
            }
        }

        long long ans = 0;
        for (auto x : m1)
        {
            long long current_max_x = x.first + (long long)(x.second - 1) * k;
            
            if (current_max_x + 1 > ans) {
                ans = current_max_x + 1;
            }
        }
        
        cout << ans << endl;
    }
    return 0;
}