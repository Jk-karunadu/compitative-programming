#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> dp(n, 1);
    int ans = 0;

    for (int i = 0; i < n; i++) {
        int current_pos = i + 1;
        for (int j = 1; j * j <= current_pos; j++) {
            if (current_pos % j == 0) {
                int p1 = j - 1;
                if (p1 < i && a[i] > a[p1]) {
                    dp[i] = max(dp[i], dp[p1] + 1);
                }
                
                int p2 = (current_pos / j) - 1;
                if (p2 < i && a[i] > a[p2]) {
                    dp[i] = max(dp[i], dp[p2] + 1);
                }
            }
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
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