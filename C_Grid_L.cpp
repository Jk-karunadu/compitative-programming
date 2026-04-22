#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
    long long n, m;
    if (!(cin >> n >> m)) return;

    long long target = 2LL * (n + 2LL * m) + 1LL;

    bool found = false;

    for (long long d = 1; d * d <= target; ++d) {
        if (target % d == 0) {
            long long d1 = d;
            long long d2 = target / d;

            if (d1 >= 3 && d1 % 2 != 0 && d2 >= 3 && d2 % 2 != 0) {
                long long r = (d1 - 1) / 2;
                long long c = (d2 - 1) / 2;

                long long min_dim = min(r, c);
                long long max_m = (r * c) + min_dim;

                if (m <= max_m) {
                    cout << r << " " << c << "\n";
                    found = true;
                    break;
                }
            }
        }
    }

    if (!found) {
        cout << -1 << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}