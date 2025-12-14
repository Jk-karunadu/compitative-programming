#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<pair<long long, int>> caves(n);
    
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        long long max_req = -2e18; 
        
        for (int j = 0; j < k; ++j) {
            long long armor;
            cin >> armor;
            if (armor + 1 - j > max_req) {
                max_req = armor + 1 - j;
            }
        }
        caves[i] = {max_req, k};
    }
    sort(caves.begin(), caves.end());
    long long ans = caves[0].first;
    long long current_power = ans;
    
    for (int i = 0; i < n; ++i) {
        if (current_power < caves[i].first) {
            long long deficit = caves[i].first - current_power;
            ans += deficit;           
            current_power += deficit; 
        }
      
        current_power += caves[i].second;
    }
    
    cout << ans << "\n";
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}