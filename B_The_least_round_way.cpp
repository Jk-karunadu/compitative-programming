#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define endl '\n'
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(v) v.begin(), v.end()
#define sz(x) (int)(x).size()

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;

#define for0(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define for1(i, n) for (ll i = 1; i <= (ll)(n); ++i)
#define forr(i, n) for (ll i = (ll)(n) - 1; i >= 0; --i)
#define fora(i, a, b) for (ll i = (ll)(a); i <= (ll)(b); ++i)
const int MOD = 1e9 + 7;
const ll INF = 1e18;
#ifndef ONLINE_JUDGE
#define debug(x)         \
    cerr << #x << " = "; \
    _print(x);           \
    cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
template <class T, class V>
void _print(pair<T, V> p)
{
    cerr << "{";
    _print(p.fi);
    cerr << ",";
    _print(p.se);
    cerr << "}";
}
template <class T>
void _print(vector<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll power(ll a, ll b, ll m = MOD)
{
    ll res = 1;
    a %= m;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int m = 1e9 + 7;
vector<long long> f, inf;

ll modex(ll base, ll exp)
{
    ll res = 1;
    while (exp)
    {
        if (exp & 1)
            res = (res * base) % m;
        base = (base * base) % m;
        exp >>= 1;
    }

    return res;
}

void precom(int n)
{
    f.resize(n + 1);
    inf.resize(n + 1);
    f[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        f[i] = (f[i - 1] * i) % m;
    }

    inf[n] = modex(f[n], m - 2);

    for (int i = n - 1; i >= 0; i--)
    {
        inf[i] = (inf[i + 1] * (i + 1)) % m;
    }
}

ll ncr(int n, int r)
{
    if (r < 0 || r > n)
        return 0;

    return (f[n] * inf[r] % m * inf[n - r] % m) % m;
}
char parent[2][1005][1005]; 

int countFactors(long long x, int f) {
    if (x == 0) return 0;
    int count = 0;
    while (x > 0 && x % f == 0) {
        count++;
        x /= f;
    }
    return count;
}

int solve_dp(int n, vector<vector<int>>& grid, vector<vector<int>>& dp, int type) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) {
                dp[i][j] = grid[i][j];
            } else {
                int up = (i > 0) ? dp[i - 1][j] : 1e9;
                int left = (j > 0) ? dp[i][j - 1] : 1e9;

                if (up < left) {
                    dp[i][j] = up + grid[i][j];
                    parent[type][i][j] = 'D';
                } else {
                    dp[i][j] = left + grid[i][j];
                    parent[type][i][j] = 'R';
                }
            }
        }
    }
    return dp[n - 1][n - 1];
}

int main() {
    fast_io;
    int n;
    if (!(cin >> n)) return 0;

    vector<vector<int>> vec2(n, vector<int>(n));
    vector<vector<int>> vec5(n, vector<int>(n));
    int zero_i = -1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            long long x;
            cin >> x;
            if (x == 0) {
                zero_i = i;
                vec2[i][j] = vec5[i][j] = 1; 
            } else {
                vec2[i][j] = countFactors(x, 2);
                vec5[i][j] = countFactors(x, 5);
            }
        }
    }

    vector<vector<int>> dp2(n, vector<int>(n, -1));
    vector<vector<int>> dp5(n, vector<int>(n, -1));

    int res2 = solve_dp(n, vec2, dp2, 0);
    int res5 = solve_dp(n, vec5, dp5, 1);

    int ans = min(res2, res5);

    if (zero_i != -1 && ans > 1) {
        cout << 1 << endl;
        for (int i = 0; i < zero_i; i++) cout << 'D';
        for (int j = 0; j < n - 1; j++) cout << 'R';
        for (int i = zero_i; i < n - 1; i++) cout << 'D';
        cout << endl;
    } else {
        cout << ans << endl;
        string path = "";
        int i = n - 1, j = n - 1;
        int type = (res2 < res5) ? 0 : 1;
        
        while (i > 0 || j > 0) {
            path += parent[type][i][j];
            if (parent[type][i][j] == 'D') i--;
            else j--;
        }
        reverse(path.begin(), path.end());
        cout << path << endl;
    }

    return 0;
}