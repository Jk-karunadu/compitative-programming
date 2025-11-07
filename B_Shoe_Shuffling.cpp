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

        
        vector<pair<long long, int>> vec(n);
        for (int i = 0; i < n; i++)
        {
            cin >> vec[i].first;
            vec[i].second = i + 1;
        }

        sort(vec.begin(), vec.end()); 

        vector<int> ans(n + 1, 0);
        bool possible = true;

        int i = 0;
        while (i < n)
        {
            int j = i;
            while (j < n && vec[j].first == vec[i].first)
                j++;

            int len = j - i;

            if (len == 1)
            {
                possible = false;
                break;
            }

           
            for (int k = 0; k < len; k++)
            {
                int next = (k + 1) % len;
                ans[vec[i + k].second] = vec[i + next].second;
            }

            i = j;
        }

        if (!possible)
        {
            cout << -1 << "\n";
        }
        else
        {
            for (int i = 1; i <= n; i++)
                cout << ans[i] << " ";
            cout << "\n";
        }
    }

    return 0;
}
