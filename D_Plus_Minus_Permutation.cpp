#include <bits/stdc++.h> 
using namespace std;


using ll = long long;


ll gcd(ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

ll lcm(ll a, ll b) {
    if (a == 0 || b == 0) return 0;
    return (a / gcd(a, b)) * b;
}

ll arithmetic_sum(ll k) {
    if (k <= 0) {
        return 0;
    }
    return k * (k + 1) / 2;
}

ll get_sum(ll a, ll b) {
    if (a > b) {
        return 0; // Handle invalid range
    }
    return arithmetic_sum(b) - arithmetic_sum(a - 1);
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        ll n, x, y;
        cin >> n >> x >> y;

      
        ll common_count = n / lcm(x, y);

        ll c1 = (n / x) - common_count;

        ll c2 = (n / y) - common_count;

        ll x_sum = get_sum(n - c1 + 1, n);

      
        ll y_sum = get_sum(1LL, c2);

        cout << (x_sum - y_sum) << endl;
    }
    return 0;
}