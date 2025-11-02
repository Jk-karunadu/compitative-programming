#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        string s;
        cin >> n >> s;
        int count = 1;
        int ans = INT_MIN;

        for (int i = 1; i < n; i++)
        {
            if (s[i] == s[i - 1])
            {
                count++;
            }
            else
            {
                ans = max(ans, count + 1);
                count = 1;
            }
        }

        ans = max(ans, count + 1);

        cout << ans << endl;
    }

    return 0;
}