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
        vector<int> b(n);

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }

        int change1 = -1, change2 = -1;

        for (int i = 0; i < n; i++)
        {
            if (a[i] != b[i])
            {
                if (change1 == -1)
                {
                    change1 = i;
                }
                change2 = i; 
            }
        }
        
        if (change1 == -1) {
            change1 = 0;
            change2 = 0;
        }

        int i = change1 - 1;
        while (i >= 0)
        {
            if (b[i] <= b[i + 1])
            {
                change1 = i;
                i--;
            }
            else
            {
                break;
            }
        }

        int j = change2 + 1;
        while (j < n)
        {
            if (b[j - 1] <= b[j])
            {
                change2 = j;
                j++;
            }
            else
            {
                break;
            }
        }

        cout << change1 + 1 << " " << change2 + 1 << "\n";
    }
    return 0;
}