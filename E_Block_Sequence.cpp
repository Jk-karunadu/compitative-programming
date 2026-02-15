#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &a, int idx, vector<int> &dp)
{
    if (idx >= a.size())
        return 0;
    if (dp[idx] != -1)
        return dp[idx];

    int ans = solve(a, idx + 1, dp);

    if (idx + a[idx] < a.size()) {
        ans = max(ans, (1 + a[idx]) + solve(a, idx + a[idx] + 1, dp));
    }

    return dp[idx] = ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &i : a)
            cin >> i;

        vector<int> dp(n + 1, -1);
        
        int max_kept = solve(a, 0, dp);
        cout << n - max_kept << endl;
    }
    return 0;
}