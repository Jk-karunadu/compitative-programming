#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<int> sp(10, 0);
    for (int i = 0; i <= 9; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            for (int k = 0; k <= 9; k++)
            {
                if (i + j + k < 10)
                    sp[i + j + k]++;
            }
        }
    }

    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        long long fans = 1;
        for (char x : s)
        {
            fans *= sp[x - '0'];
        }
        cout << fans << "\n";
    }

    return 0;
}