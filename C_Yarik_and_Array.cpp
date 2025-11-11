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

        vector<int> vec(n);
        for (int i = 0; i < n; i++)
        {
            cin >> vec[i];
        }

        long long sum = vec[0];
        long long ans = vec[0];

        for (int i = 1; i < n; i++)
        {
            
            if ((vec[i] & 1) != (vec[i - 1] & 1))
            {
                
                sum = max((long long)vec[i], sum + vec[i]);
            }
            else
            {
                
                sum = vec[i];
            }
            ans = max(ans, sum);
        }

        cout << ans << "\n";
    }
    return 0;
}