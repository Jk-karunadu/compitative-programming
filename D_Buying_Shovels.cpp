#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

void solve() {
    long long n, k;
    cin >> n >> k;
    if (k >= n) {
        cout << 1 << endl;
        return;
    }

    long long min_packages = n;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            if (i <= k) {
                min_packages = min(min_packages, n / i);
            }

            if (n / i <= k) {
                min_packages = min(min_packages, i);
            }
        }
    }

    cout << min_packages << endl;
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