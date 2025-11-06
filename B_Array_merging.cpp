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
        unordered_map<int, int> m;

        for (int i = 0; i < 2 * n; i++)
        {
            int x;
            cin >> x;
            m[x]++;
        }

        int maxOccur = 0;

        for (auto &p : m)
        {
            maxOccur = max(maxOccur, p.second);
        }

       
        cout << min(n, maxOccur) << endl;
      
    }
}
