#include <iostream>
#include <vector>
#include <map>

using namespace std;

void solve() {
    int n;
    long long x, y; 
    cin >> n >> x >> y;
    
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    map<pair<int, int>, int> seen_counts;
    long long ans = 0;
    
    for (int val : a) {
        int cur_rx = val % x;
        int cur_ry = val % y;
        int target_rx = (x - cur_rx) % x;
        int target_ry = cur_ry; 
        
        if (seen_counts.count({target_rx, target_ry})) {
            ans += seen_counts[{target_rx, target_ry}];
        }
        seen_counts[{cur_rx, cur_ry}]++;
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