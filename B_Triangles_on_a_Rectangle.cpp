#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int w, h;
        cin >> w >> h;
        int ans = INT_MIN ;

        for (int i = 0; i < 2; i++)
        {
            int k;
            cin >> k;
            int mn = INT_MAX;
            int mx = INT_MIN;
            for (int i = 0; i < k; i++)
            {
                int x;
                cin >> x;

                mn = min(mn, x);
                mx = max(mx, x);
            }
            ans = max(ans, abs(mx - mn) * h );
        }

        for (int i = 0; i < 2; i++)
        {
            int k;
            cin >> k;
            int mn = INT_MAX;
            int mx = INT_MIN;
            for (int i = 0; i < k; i++)
            {
                int x;
                cin >> x;

                mn = min(mn, x);
                mx = max(mx, x);
            }
            ans = max(ans, abs(mx - mn) * w );
        }

        cout<<ans<<endl;
    }
}