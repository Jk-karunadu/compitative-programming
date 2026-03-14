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
        string s;
        cin >> s;
        
       
        int ans = n;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
            {
                
                int left_dist = i + 1;
                int right_dist = n - i;
                
                ans = max(ans, 2 * left_dist);
                ans = max(ans, 2 * right_dist);
            }
        }
        cout << ans << endl;
    }
    return 0;
}