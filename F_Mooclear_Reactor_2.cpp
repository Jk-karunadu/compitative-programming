#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

// Fenwick Tree (Binary Indexed Tree) to manage particle counts and energy sums
struct FenwickTree {
    int n;
    vector<ll> count;
    vector<ll> sum;

    FenwickTree(int size) : n(size), count(size + 1, 0), sum(size + 1, 0) {}

    // Update the tree when a new particle becomes eligible
    void update(int idx, ll val, int delta) {
        for (; idx <= n; idx += idx & -idx) {
            count[idx] += delta;
            sum[idx] += (ll)val * delta;
        }
    }

    // Binary lifting on the Fenwick Tree to find the sum of top k elements in O(log N)
    ll query_top_k(int k, const vector<ll>& sorted_vals) {
        if (k <= 0) return 0;
        int idx = 0;
        int current_k = k;
        
        // Find the rank where we reach the k-th element
        for (int i = 1 << 18; i > 0; i >>= 1) {
            if (idx + i <= n && count[idx + i] < current_k) {
                idx += i;
                current_k -= count[idx];
            }
        }

        ll res = 0;
        int temp_idx = idx;
        while (temp_idx > 0) {
            res += sum[temp_idx];
            temp_idx -= temp_idx & -temp_idx;
        }

        // Add the remaining 'current_k' elements from the next distinct value rank
        if (idx < n) {
            res += (ll)current_k * sorted_vals[idx];
        }
        return res;
    }
};

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;

    vector<pair<ll, int>> bessie(n);
    vector<ll> distinct_x;
    for (int i = 0; i < n; i++) {
        cin >> bessie[i].first >> bessie[i].second;
        distinct_x.push_back(bessie[i].first);
    }

    // Coordinate compression preparation: sort energies in descending order
    sort(distinct_x.begin(), distinct_x.end(), greater<ll>());
    
    // Grouping by reactivity y to process them as 'k' decreases
    vector<vector<ll>> by_y(n + 1);
    for (auto& p : bessie) {
        by_y[p.second].push_back(p.first); // Fixed: using .second for reactivity y
    }

    FenwickTree ft(n);
    ll global_max_no_shop = 0;
    vector<ll> G(n + 1, 0);

    // Process from largest size down to 1
    for (int k = n + 1; k >= 1; k--) {
        // Particles with y >= k-1 become eligible for a subset of size k
        if (k - 1 <= n) {
            for (ll val : by_y[k - 1]) {
                int rank = lower_bound(distinct_x.begin(), distinct_x.end(), val, greater<ll>()) - distinct_x.begin() + 1;
                ft.update(rank, val, 1);
            }
        }

        // Fast count of current eligible particles
        int total_available = 0;
        for (int i = n; i > 0; i -= i & -i) total_available += ft.count[i];

        // Max energy with only Bessie's particles (size k)
        if (total_available >= k) {
            global_max_no_shop = max(global_max_no_shop, ft.query_top_k(k, distinct_x));
        }

        // Best sum of k-1 particles to pair with a shop particle
        if (total_available >= k - 1 && k > 1) {
            G[k - 1] = ft.query_top_k(k - 1, distinct_x);
        }
    }

    // Prefix max: if shop particle reactivity is Y, it can join any group size <= Y+1
    for (int i = 1; i <= n; i++) G[i] = max(G[i], G[i - 1]);

    for (int i = 0; i < m; i++) {
        ll xj;
        int yj;
        cin >> xj >> yj;
        // The answer is either the best Bessie-only set or the shop + best Bessie k-1 set
        ll ans = max(global_max_no_shop, xj + G[min(n, yj)]);
        cout << ans << (i == m - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (!(cin >> t)) return 0;
    while (t--) solve();
    return 0;
}