#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
bool is_possible(vector<pair<ll, ll>> &segments, ll k)
{
    ll min_pos = 0;
    ll max_pos = 0;

    for (const auto& seg : segments)
    {
        min_pos = min_pos - k;
        max_pos = max_pos + k;

        min_pos = max(min_pos, seg.first);
        max_pos = min(max_pos, seg.second);

        if (min_pos > max_pos)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<pair<ll, ll>> segments(n);

        for (int i = 0; i < n; i++)
        {
            cin >> segments[i].first >> segments[i].second;
        }

        ll l = 0;
        ll h = 1e9; 
        ll ans = h;

        while (l <= h)
        {
            ll mid = l + (h - l) / 2;
            if (is_possible(segments, mid))
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