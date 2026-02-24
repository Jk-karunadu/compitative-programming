#include <bits/stdc++.h>
using namespace std;
int main()
{
     ios_base::sync_with_stdio(false);
    cin.tie(0);

    
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            m[x]++;
        }
        int ans = 0;
        for (auto &a : m)
        {
            ans = ans + a.second / 2;
        }
        cout << ans << endl;
    }
}