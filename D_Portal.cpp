#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to compare two rotations and find the smaller one
bool is_smaller(const vector<int>& p, int start1, int start2, int n) {
    for (int i = 0; i < n; i++) {
        if (p[(start1 + i) % n] < p[(start2 + i) % n]) return true;
        if (p[(start1 + i) % n] > p[(start2 + i) % n]) return false;
    }
    return false;
}

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];

    // Based on the portal mechanics, we can reach any cyclic shift 
    // where the jump happens between the portals.
    // The most efficient way is to find the minimum cyclic shift of the array.
    
    int best_start = 0;
    for (int i = 1; i < n; i++) {
        if (is_smaller(p, i, best_start, n)) {
            best_start = i;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << p[(best_start + i) % n] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
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