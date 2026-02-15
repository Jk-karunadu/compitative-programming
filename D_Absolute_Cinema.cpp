#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<ll> f(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> f[i];
    }

    if (n == 0) return;

    vector<ll> a(n + 1);

    for (int i = 2; i < n; i++) {
        a[i] = (f[i + 1] - 2 * f[i] + f[i - 1]) / 2;
    }

    ll sum_middle_f1 = 0;
    for (int i = 2; i < n; i++) {
        sum_middle_f1 += a[i] * (i - 1);
    }
    a[n] = (f[1] - sum_middle_f1) / (n - 1);

    ll sum_middle_fn = 0;
    for (int i = 2; i < n; i++) {
        sum_middle_fn += a[i] * (n - i);
    }
    a[1] = (f[n] - sum_middle_fn) / (n - 1);

    for (int i = 1; i <= n; i++) {
        cout << a[i] << (i == n ? "" : " ");
    }
    cout << "\n";
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