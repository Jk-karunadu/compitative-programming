#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int dp[2005][2005];

int solve(int len, int prev, int n, int k)
{
    if (len == k)
        return 1;
        
    if (dp[len][prev] != -1)
        return dp[len][prev];

    long long ans = 0;
    
    for (int next_val = prev; next_val <= n; next_val += prev)
    {
        ans = (ans + solve(len + 1, next_val, n, k)) % MOD;
    }

    return dp[len][prev] = (int)ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    if (!(cin >> n >> k)) return 0;

    memset(dp, -1, sizeof(dp));

    long long total_ans = 0;
    for (int i = 1; i <= n; i++)
    {
        total_ans = (total_ans + solve(1, i, n, k)) % MOD;
    }

    cout << total_ans << endl;
    
    return 0;
}