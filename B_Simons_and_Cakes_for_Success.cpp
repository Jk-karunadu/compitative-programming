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

        long long t = n;
        long long k = 1;
        for (long long i = 2; i * i <= t; i++)
        {
            if (t % i == 0)
            {
                k *= i;
                while (t % i == 0)
                {
                    t /= i;
                }
            }
        }

        if (t > 1)
        {
            k *= t;
        }
        cout << k << endl;
    }
    return 0;
}