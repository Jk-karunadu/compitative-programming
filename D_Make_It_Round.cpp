#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    ll n, m;
    cin >> n >> m;

    ll temp_n = n;
    int c2 = 0, c5 = 0;

    // Count factors of 2 in n
    while (temp_n > 0 && temp_n % 2 == 0) {
        c2++;
        temp_n /= 2;
    }
    // Count factors of 5 in n
    while (temp_n > 0 && temp_n % 5 == 0) {
        c5++;
        temp_n /= 5;
    }

    ll k = 1;

    // Step 1: Balance 2s and 5s to create 10s
    // If n has more 2s, multiply k by 5s
    while (c2 > c5 && k * 5 <= m) {
        k *= 5;
        c5++;
    }
    // If n has more 5s, multiply k by 2s
    while (c5 > c2 && k * 2 <= m) {
        k *= 2;
        c2++;
    }

    // Step 2: Multiply k by 10s as much as possible
    while (k * 10 <= m) {
        k *= 10;
    }

    // Step 3: Maximize k within the range m
    // We have the best power of 10, now find the largest multiple
    if (k > 0) {
        k = m-m%k;
    }

    if (k == 0) k = m; 

    cout << n * k << "\n";
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