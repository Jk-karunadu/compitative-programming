#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>

using namespace std;

typedef long long ll;

ll find_gcd(ll a, ll b) {
    a = abs(a);
    b = abs(b);
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    ll g = 0;
    for (int i = 1; i < n; i++) {
        g = find_gcd(g, a[i] - a[0]);
    }
    for (int j = 0; j < m; j++) {
        ll b_val;
        cin >> b_val;
        cout << find_gcd(a[0] + b_val, g) << (j == m - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}