#include <iostream>

using namespace std;

void solve() {
    long long n, m;
    if (!(cin >> n >> m)) return;

    if (n == 1) {
        cout << 0 << "\n";
    } 
    else if (n == 2) {
        cout << m << "\n";
    } 
    else {
        cout << 2 * m << "\n";
    }
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