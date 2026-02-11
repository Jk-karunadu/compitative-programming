#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll sum_digits(ll n) {
    ll s = 0;
    while (n > 0) {
        s += n % 10;
        n /= 10;
    }
    return s;
}

void solve() {
    ll x;
    cin >> x;

    if (x % 9 != 0) {
        cout << 0 << "\n";
        return;
    }
    int count = 0;
    for (ll y = x; y <= x + 170; y++) {
        if (y - sum_digits(y) == x) {
            count++;
        }
    }

    cout << count << "\n";
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