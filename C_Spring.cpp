#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

ll safe_lcm(ll a, ll b, ll m) {
    if (a == 0 || b == 0) return 0;
    ll common = gcd(a, b);
    
    ll part = a / common;
    if (part > m / b) return m + 1; // Overflow relative to m
    
    return part * b;
}

void solve() {
    ll a, b, c, m;
    if (!(cin >> a >> b >> c >> m)) return;

    ll ab = safe_lcm(a, b, m);
    ll bc = safe_lcm(b, c, m);
    ll ac = safe_lcm(a, c, m);
    ll abc = safe_lcm(ab, c, m);

    ll count_abc = m / abc;
    
    ll count_ab = (m / ab) - count_abc;
    ll count_bc = (m / bc) - count_abc;
    ll count_ac = (m / ac) - count_abc;

    ll count_a = (m / a) - (count_ab + count_ac + count_abc);
    ll count_b = (m / b) - (count_ab + count_bc + count_abc);
    ll count_c = (m / c) - (count_ac + count_bc + count_abc);

    ll ansA = (count_a * 6) + (count_ab * 3) + (count_ac * 3) + (count_abc * 2);
    ll ansB = (count_b * 6) + (count_ab * 3) + (count_bc * 3) + (count_abc * 2);
    ll ansC = (count_c * 6) + (count_ac * 3) + (count_bc * 3) + (count_abc * 2);

    cout << ansA << " " << ansB << " " << ansC << "\n";
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