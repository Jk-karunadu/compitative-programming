#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    if (k >= 3) {
        cout << 0 << endl;
        return;
    }

    sort(a.begin(), a.end());
    ll ans = a[0];

    for (int i = 0; i < n - 1; i++) {
        ans = min(ans, a[i + 1] - a[i]);
    }

    if (k == 1) {
        cout << ans << endl;
        return;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            ll diff = a[i] - a[j];
            
            auto it = lower_bound(a.begin(), a.end(), diff);
            
            if (it != a.end()) ans = min(ans, *it - diff);
            if (it != a.begin()) ans = min(ans, diff - *prev(it));
        }
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}