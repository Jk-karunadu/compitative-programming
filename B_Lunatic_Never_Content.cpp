#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<long long> vec(n);

        for (int i = 0; i < n; i++)
        {
            cin >> vec[i];
        }
        long long ans = abs(vec[0] - vec[n - 1]);

        for (int i = 1; i < n / 2; i++)
        {
            ans = __gcd(ans, abs(vec[i] - vec[n - 1 - i]));
        }
        cout << ans << endl;
    }
}