#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool check(int n, int m, unordered_map<int, int> &mp, int m_time)
{
    ll free_slots = 0;
    ll extra_tasks = 0;

    for (int i = 1; i <= n; i++) {
        int tasks_assigned = 0;
        if (mp.count(i)) {
            tasks_assigned = mp[i];
        }

        if (m_time >= tasks_assigned) {
            free_slots += (m_time - tasks_assigned) / 2;
        } else {
            extra_tasks += (tasks_assigned - m_time);
        }
    }

    return free_slots >= extra_tasks;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        unordered_map<int, int> mp;
        for (int i = 0; i < m; i++)
        {
            int x;
            cin >> x;
            mp[x]++;
        }

        int l = 1;
        int h = 2 * m; 
        int ans = h;

        while (l <= h)
        {
            int mid = l + (h - l) / 2;

            if (check(n, m, mp, mid))
            {
                ans = mid;
                h = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}