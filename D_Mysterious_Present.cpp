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

struct Envelope {
    int w, h, id;
};

void solve() {
    int n, w, h;
    if (!(cin >> n >> w >> h)) return;

    vector<Envelope> envs;
    for (int i = 1; i <= n; i++) {
        int wi, hi;
        cin >> wi >> hi;
        // Only keep envelopes the card actually fits into
        if (wi > w && hi > h) {
            envs.push_back({wi, hi, i});
        }
    }

    // If no envelopes fit the card
    if (envs.empty()) {
        cout << 0 << endl;
        return;
    }

    // Sort by width, then height
    sort(envs.begin(), envs.end(), [](const Envelope& a, const Envelope& b) {
        if (a.w == b.w) return a.h < b.h;
        return a.w < b.w;
    });

    int m = envs.size();
    vector<int> dp(m, 1);
    vector<int> parent(m, -1);

    int max_len = 1;
    int best_idx = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < i; j++) {
            if (envs[i].w > envs[j].w && envs[i].h > envs[j].h) {
                if (dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                }
            }
        }
        if (dp[i] > max_len) {
            max_len = dp[i];
            best_idx = i;
        }
    }

    cout << max_len << endl;
    
    vector<int> path;
    for (int curr = best_idx; curr != -1; curr = parent[curr]) {
        path.push_back(envs[curr].id);
    }
    
    reverse(path.begin(), path.end());
    for (int i = 0; i < path.size(); i++) {
        cout << path[i] << (i == path.size() - 1 ? "" : " ");
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}