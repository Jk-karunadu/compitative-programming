#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for (int t = 0; t < T; ++t) {
        int n, m;
        cin >> n >> m;

        vector<ll> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<ll> b(m), c(m);
        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> c[i];
        }

        vector<pair<ll, ll>> upg; // monsters with upgrades
        vector<ll> cons;          // monsters without upgrades

        for (int i = 0; i < m; i++) {
            if (c[i] > 0)
                upg.push_back(make_pair(b[i], c[i]));
            else
                cons.push_back(b[i]);
        }

        sort(upg.begin(), upg.end());
        sort(cons.begin(), cons.end());

        multiset<ll> avail;
        for (int i = 0; i < n; i++) {
            avail.insert(a[i]);
        }

        int killed = 0;

        // Process monsters that can upgrade your sword
        for (int i = 0; i < (int)upg.size(); i++) {
            ll bb = upg[i].first;
            ll cc = upg[i].second;

            multiset<ll>::iterator it = avail.lower_bound(bb);
            if (it == avail.end()) continue;

            ll x = *it;
            avail.erase(it);
            killed++;
            avail.insert((std::max)(x, cc));
        }

        // Process monsters that consume swords (no upgrades)
        for (int i = 0; i < (int)cons.size(); i++) {
            ll bb = cons[i];

            multiset<ll>::iterator it = avail.lower_bound(bb);
            if (it == avail.end()) continue;

            ll x = *it;
            avail.erase(it);
            killed++;
        }

        cout << killed << '\n';
    }

    return 0;
}
