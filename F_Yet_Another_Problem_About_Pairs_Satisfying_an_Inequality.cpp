#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> valid_indices;
    
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i] < i) {
            valid_indices.push_back(i);
        }
    }
    
    long long ans = 0;
    for (int j : valid_indices) {
        
        long long count = lower_bound(valid_indices.begin(), valid_indices.end(), a[j]) - valid_indices.begin();
        
        ans += count;
    }
    
    cout << ans << "\n";
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