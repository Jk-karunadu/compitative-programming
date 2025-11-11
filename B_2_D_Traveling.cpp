#include <bits/stdc++.h>
using namespace std;

int main()
{
  

    int t;
    cin >> t;

    while (t--)
    {
        int n, k, a, b;
        cin >> n >> k >> a >> b;

        vector<long long> x(n);
        vector<long long> y(n);

        for (int i = 0; i < n; i++)
        {
            cin >> x[i];
            cin >> y[i];
        }

       
        long long ans = abs(x[a - 1] - x[b - 1]) + abs(y[a - 1] - y[b - 1]);

        
        long long mina = LLONG_MAX;
        long long minb = LLONG_MAX;

       
        for (int i = 0; i < k; i++)
        {
           
            mina = min(mina, abs(x[i] - x[a - 1]) + abs(y[i] - y[a - 1]));
           
            minb = min(minb, abs(x[i] - x[b - 1]) + abs(y[i] - y[b - 1]));
        }

      
        if (k > 0)
        {
            ans = min(ans, mina + minb);
        }
        
        cout << ans << "\n"; 
    }
    return 0; 
}