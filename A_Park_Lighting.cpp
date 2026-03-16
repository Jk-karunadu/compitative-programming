#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        int ans = 0;
        
        while (n >= 2)
        {
            ans = ans + m; 
            n = n - 2;
        }

        if (n > 0)
        {
            if (m % 2 == 0)
            {
                ans = ans + m / 2;
            }
            else
            {
                ans = ans + (m / 2) + 1;
            }
        }

        cout << ans << endl;
    }

    return 0;
}