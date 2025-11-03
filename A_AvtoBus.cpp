#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        long long n;

        cin >> n;

        if (n % 2 == 0 && n >= 4)
        {

            long long x1 = n % 4;
            long long x2 = n % 6;
            long long min = n / 6;
            long long max = n / 4;

            if (x2 > 0)
            {
                min = min + 1;
            }

            cout << min << " " << max << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
}