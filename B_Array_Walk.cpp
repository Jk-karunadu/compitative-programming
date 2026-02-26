#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n, k, z;
    cin >> n >> k >> z;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<vector<int>> dp(k + 1, vector<int>(z + 1, 0));

    int ans = 0;
    
    dp[0][0] = a[0];

    for (int j = 0; j <= z; j++) {
        for (int i = 0; i <= k; i++) {
            int idx = i - 2 * j;
            
            if (idx < 0 || idx >= n) continue;

            if (i < k && idx + 1 < n) {
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + a[idx + 1]);
            }

            if (i < k && j < z && idx - 1 >= 0) {
                dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + a[idx - 1]);
            }
            
            if (i == k) ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}