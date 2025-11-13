#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        
        int last_dig = a[n - 1];
        int count = 0;
        
        for (int i = n - 2; i >= 0;)
        {
            if (a[i] != last_dig)
            {
                count++;
                int good_suffix_length = n - 1 - i;
                i = i - good_suffix_length;
            }
            else
            {
                i--;
            }
        }
        cout << count << "\n";
    }
    return 0;
}