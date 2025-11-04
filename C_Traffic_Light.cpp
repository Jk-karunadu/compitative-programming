#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        char c;
        cin >> n >> c;

        string s;
        cin >> s;

       
        s += s;
        int ans = 0;
        int last_g = -1;

      
        for (int i = 2 * n - 1; i >= 0; i--)
        {
            if (s[i] == 'g')
                last_g = i;
            if (s[i] == c && last_g != -1)
                ans = max(ans, last_g - i);
        }

        cout << ans << endl;
    }
}
