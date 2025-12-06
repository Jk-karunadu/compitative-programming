#include <iostream>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    if (n % 2 == 0) {
        long long k = n / 2;
        cout << (k + 1) * (k + 1) << "\n";
    } else {
        long long k1 = (n + 1) / 2; 
        long long k2 = (n - 1) / 2; 
        cout << 2 * (k1 + 1) * (k2 + 1) << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}