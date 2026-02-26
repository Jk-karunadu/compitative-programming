#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

typedef long long ll;

ll find_gcd(ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

ll find_lcm(ll a, ll b) {
    if (a == 0 || b == 0) return 0;
    return (a * b) / find_gcd(a, b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<ll> suffix(n + 1, 0);
    for (int i = n - 1; i >= 0; i--) {
        suffix[i] = find_gcd(a[i], suffix[i + 1]);
    }

    ll final_ans = 0;
    for (int i = 0; i < n - 1; i++) {
        ll current_lcm = find_lcm(a[i], suffix[i + 1]);
        if (final_ans == 0) {
            final_ans = current_lcm;
        } else {
            final_ans = find_gcd(final_ans, current_lcm);
        }
    }

    cout << final_ans << endl;

    return 0;
}