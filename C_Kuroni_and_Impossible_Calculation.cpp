#include <bits/stdc++.h>
using namespace std;

int main()
{
   
    int n, m;
    cin >> n >> m;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    long long ans = 1;

    if (n > m)
    {
        ans = 0;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                ans *= (abs(a[j] - a[i]) % m);
                ans %= m;
            }
        }
    }

    cout<<ans<<endl;
}