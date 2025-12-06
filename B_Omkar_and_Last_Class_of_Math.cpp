#include <iostream>

using namespace std;

void solve() {
    int n;
    cin >> n;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            cout << n / i << " " << n - (n / i) << "\n";
            return;
        }
    }
    cout << 1 << " " << n - 1 << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}