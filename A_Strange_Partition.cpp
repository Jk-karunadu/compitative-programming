#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        long long n, x;
        cin >> n >> x;

        long long sum = 0;
        long long mx = 0;

        for (int i = 0; i < n; i++)
        {
            long long k;
            cin >> k;

            sum += k;
          
            mx += (long long)ceil((double)k / x);
        }

        long long mn = (long long)ceil((double)sum / x);

        cout << mn << " " << mx << endl;
    }
    return 0;
}
