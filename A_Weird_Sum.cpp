#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    unordered_map<int, vector<pair<int, int>>> mp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int x;
            cin >> x;
            mp[x].push_back({i, j});
        }
    }

    ll total_sum = 0; 

    for (auto &it : mp)
    {
        vector<pair<int, int>> &v = it.second;
        int k = v.size();
        
        sort(v.begin(), v.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
            return a.first < b.first;
        });

        ll x_sum = 0;
        ll j_val = 1;
        for (int i = 0; i < k; i++)
        {
            x_sum = x_sum + (ll)v[i].first * (k - j_val);
            j_val = j_val + 2;
        }

        sort(v.begin(), v.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
            return a.second < b.second;
        });

        ll y_sum = 0;
        j_val = 1;
        for (int i = 0; i < k; i++)
        {
            y_sum = y_sum + (ll)v[i].second * (k - j_val);
            j_val = j_val + 2;
        }

        total_sum = total_sum + abs(x_sum) + abs(y_sum);
    }

    cout << total_sum << "\n";
    return 0;
}