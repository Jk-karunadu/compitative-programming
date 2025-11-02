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
        bool found = false;
        long long i = 1;

        for (; i < n; i++)
        {
            if (n % i != 0)
            {
                found = true;
                cout << i - 1 << endl;
                break;
            }
        }
        if (!found)
        {
            cout << i << endl;
        }
    }

    return 0;
}
