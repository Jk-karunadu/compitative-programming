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
#define for1(i, n) for (ll i = 1; i < (ll)(n); ++i)
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

ll modpow(ll a, ll b)
{
    ll r = 1;

    while (b)
    {
        if (b & 1)
            r = r * a % m;

        a = a * a % m;

        b >>= 1;
    }

    return r;
}

struct Node
{
    ll val;

    Node(ll val_) : val(val_) {}
};

class SegmentTree
{
private:
    ll n;
    vector<Node> tree;

    Node op(Node a, Node b) { return Node(max(a.val, b.val)); }

    Node e() { return Node(LLONG_MIN); }

    void build(vector<ll> &a, ll u, ll l, ll r)
    {
        if (l == r)
        {
            tree[u] = Node(a[l]);
        }
        else
        {
            ll m = (l + r) / 2;
            build(a, 2 * u, l, m);
            build(a, 2 * u + 1, m + 1, r);
            tree[u] = op(tree[2 * u], tree[2 * u + 1]);
        }
    }

    void update(ll u, ll idx, ll l, ll r, ll val)
    {
        if (l == r)
        {
            tree[u] = Node(val);
        }
        else
        {
            ll m = (l + r) / 2;
            if (idx <= m)
            {
                update(2 * u, idx, l, m, val);
            }
            else
            {
                update(2 * u + 1, idx, m + 1, r, val);
            }
            tree[u] = op(tree[2 * u], tree[2 * u + 1]);
        }
    }

    Node query(ll u, ll ql, ll qr, ll l, ll r)
    {
        if (ql > qr)
            return e();
        if (ql == l && qr == r)
            return tree[u];
        ll m = (l + r) / 2;
        return op(query(2 * u, ql, min(qr, m), l, m), query(2 * u + 1, max(ql, m + 1), qr, m + 1, r));
    }

public:
    SegmentTree(ll n_) : n(n_) { tree.resize(4 * n, e()); }
    SegmentTree(ll n_, Node x) : n(n_) { tree.resize(4 * n, x); }
    SegmentTree(vector<ll> &a) : SegmentTree((a.size())) { build(a, 1, 0, n - 1); }
    void update(ll idx, ll val) { update(1, idx, 0, n - 1, val); }
    Node query(ll l, ll r) { return query(1, l, r, 0, n - 1); }
    Node get(ll idx) { return query(idx, idx); }
    void set(ll idx, ll val) { update(idx, val); }
};

ll isqrt(ll x)
{

    ll lo = 0, hi = 1;

    while (hi <= x / hi)
        hi <<= 1;

    while (lo + 1 < hi)
    {

        ll mid = lo + (hi - lo) / 2;

        if (mid <= x / mid)
            lo = mid;
        else
            hi = mid;
    }

    return lo;
}
void solve()
{
    int n, s;
    cin >> n >> s;

    vi a(n);

    for0(i, n)
    {
        cin >> a[i];
    }

    int total = 0;

    for0(i, n)
    {
        total += a[i];
    }

    if (total < s)
    {
        cout << -1 << endl;
        return;
    }

    if (total == s)
    {
        cout << 0 << endl;
        return;
    }

    int sum = 0;
    int i = 0;
    int ans = 0;

    for (int j = 0; j < n; j++)
    {
        sum += a[j];

        while (sum > s)
        {
            sum -= a[i];
            i++;
        }

        if (sum == s)
        {
            ans = max(ans, j - i + 1);
        }
    }

    cout << n - ans << endl;
}

int main()
{
    fast_io;
    int t = 1;
    if (!(cin >> t))
        return 0;
    while (t--)
        solve();
    return 0;
}