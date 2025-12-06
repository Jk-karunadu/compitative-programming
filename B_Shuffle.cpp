#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
    int n, x, m;
    cin >> n >> x >> m;
    int current_L = x;
    int current_R = x;
    
    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        
        if (r < current_L || l > current_R) {
            continue;
        } else {
            current_L = min(current_L, l);
            current_R = max(current_R, r);
        }
    }
    
    cout << current_R - current_L + 1 << "\n";
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