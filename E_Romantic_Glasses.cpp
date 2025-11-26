#include <iostream>
#include <vector>
#include <set>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    set<long long> seen_sums;
    seen_sums.insert(0);
    
    long long current_sum = 0;
    bool found = false;

    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            current_sum += a[i];
        } else {
            current_sum -= a[i];
        }
        if (seen_sums.count(current_sum)) {
            found = true;
            break; 
        }
        seen_sums.insert(current_sum);
    }

    if (found) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
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