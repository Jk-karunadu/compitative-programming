#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<long long> h1(n), h2(n);
    for (int i = 0; i < n; i++) cin >> h1[i];
    for (int i = 0; i < n; i++) cin >> h2[i];

    vector<vector<long long>> dp(n, vector<long long>(2));

    dp[0][0] = h1[0];
    dp[0][1] = h2[0];

    for (int i = 1; i < n; i++) {
        dp[i][0] = max(dp[i-1][0], dp[i-1][1] + h1[i]);
        
        dp[i][1] = max(dp[i-1][1], dp[i-1][0] + h2[i]);
    }

    cout << max(dp[n-1][0], dp[n-1][1]) << endl;

    return 0;
}