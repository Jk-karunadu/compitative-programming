#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 998244353LL;

#define fo(i, n) for (int i = 0; i < n; ++i)
#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define RFOR(i, a, b) for (int i = a; i >= b; --i)
#define each(x, a) for (auto &x : a)

vector<ll> compute_dp_table(const vector<int> &fs, int n)
{
    vector<ll> dp(n + 1, 0LL);
    dp[0] = 1LL;

    each(f, fs)
    {

        RFOR(s, n, f)
        {
            dp[s] = (dp[s] + 1LL * f * dp[s - f] % MOD) % MOD;
        }
    }
    return dp;
}

void solve()
{

    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> freq(n + 1, 0);
    vector<int> fs;
    int maxf = 0;
    ll prod = 1LL;
    ll small = 0LL;
    ll ans = 0LL;

    fo(i, n)
    {
        cin >> a[i];
    }

    each(x, a)
    {
        ++freq[x];
    }

    FOR(i, 1, n)
    {
        if (freq[i] > 0)
        {
            fs.push_back(freq[i]);
            maxf = max(maxf, freq[i]);
        }
    }

    each(f, fs)
    {
        prod = prod * (1LL + f) % MOD;
    }

    vector<ll> dp = compute_dp_table(fs, n);

    fo(s, maxf)
    {
        small = (small + dp[s]) % MOD;
    }

    ans = (prod - small + MOD) % MOD;
    cout << ans << '\n';
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    fo(test, t)
    {
        solve();
    }

    return 0;
}