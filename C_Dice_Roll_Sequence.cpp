#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

bool is_adjacent(int u, int v) {
    if (u == v) return false;        
    if (u + v == 7) return false;    
    return true;                     
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> dp(7, 0);

    for (int f = 1; f <= 6; f++) {
        dp[f] = (a[0] == f ? 0 : 1);
    }

    for (int i = 1; i < n; i++) {
        vector<int> next_dp(7, INF);
        for (int curr_f = 1; curr_f <= 6; curr_f++) {
            int cost = (a[i] == curr_f ? 0 : 1);
            
            for (int prev_f = 1; prev_f <= 6; prev_f++) {
                if (is_adjacent(curr_f, prev_f)) {
                    next_dp[curr_f] = min(next_dp[curr_f], dp[prev_f] + cost);
                }
            }
        }
        dp = next_dp;
    }

    int ans = INF;
    for (int f = 1; f <= 6; f++) {
        ans = min(ans, dp[f]);
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