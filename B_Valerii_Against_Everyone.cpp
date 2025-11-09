#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n

            ;
        cin >> n;
        unordered_map<long long, bool> m;
        bool found = false;
        for (int i = 0; i < n; i++)
        {

            long long x;
            cin >> x;
            if (m[x] == true)
            {

                found = true;
            }
            else
            {
                m[x] = true;
            }
        }
        if (found)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}