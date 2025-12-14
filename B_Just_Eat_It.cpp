#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    long long total_sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        total_sum += a[i];
    }
    long long current_prefix_sum = 0;
    for (int i = 0; i < n - 1; i++) {
        current_prefix_sum += a[i];
        if (current_prefix_sum >= total_sum) {
            cout << "NO" << endl;
            return;
        }
    }
    long long current_suffix_sum = 0;
    for (int i = n - 1; i > 0; i--) {
        current_suffix_sum += a[i];
        if (current_suffix_sum >= total_sum) {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
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