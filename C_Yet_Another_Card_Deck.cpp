#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    vector<int> t(q);
    unordered_map<int, int> first_index;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];

        if (first_index.count(a[i]) == 0)
        {
            first_index[a[i]] = i;
        }
    }

    for (int i = 0; i < q; i++)
    {
        cin >> t[i];
    }

    for (int i = 0; i < q; i++)
    {
        int color_to_find = t[i];
        int current_pos = first_index[color_to_find];

        cout << current_pos + 1 << " ";

        for (auto &pair : first_index)
        {
            if (pair.second < current_pos)
            {
                pair.second++;
            }
        }
        first_index[color_to_find] = 0;
    }
    cout << "\n";
    return 0;
}