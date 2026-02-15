#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<vector<int>> current_vals(n + 1);
    vector<vector<int>> target_vals(n + 1);

    for (int i = 1; i <= n; i++) {
        int root = i;
        while (root % 2 == 0) {
            root /= 2;
        }
        current_vals[root].push_back(a[i]);
        target_vals[root].push_back(i); 
    }

    bool possible = true;
    for (int i = 1; i <= n; i++) {
        if (current_vals[i].empty()) continue;

        sort(current_vals[i].begin(), current_vals[i].end());
        
        if (current_vals[i] != target_vals[i]) {
            possible = false;
            break;
        }
    }

    if (possible) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Speed up I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}