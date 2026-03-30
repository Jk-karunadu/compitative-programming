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
ll power(ll a, ll b, ll m = MOD){ ll res = 1;a %= m;while (b > 0){ if (b & 1)res = res * a % m;a = a * a % m; b >>= 1;}return res;}
int m = 1e9 + 7;
vector<long long> f, inf;
ll modex(ll base, ll exp){ ll res = 1;while (exp){ if (exp & 1) res = (res * base) % m;base = (base * base) % m; exp >>= 1;}return res;}
void precom(int n){f.resize(n + 1);inf.resize(n + 1);f[0] = 1;for (int i = 1; i <= n; i++){f[i] = (f[i - 1] * i) % m;} inf[n] = modex(f[n], m - 2);for (int i = n - 1; i >= 0; i--){inf[i] = (inf[i + 1] * (i + 1)) % m;}}
ll ncr(int n, int r){ if (r < 0 || r > n)  return 0;return (f[n] * inf[r] % m * inf[n - r] % m) % m;}
long long lcm(long long a, long long b) {
    if (a == 0 || b == 0) return 0;
    return abs(a / gcd(a, b) * b);
}


void solve() {
    int n;
    cin >> n;
    vector<long long> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    int operations = 0;

    for (int i = 0; i < n; i++) {
        long long required_multiple;

        if (i == 0) {
            required_multiple = gcd(a[i], a[i + 1]);
        } 
        else if (i == n - 1) {
            required_multiple = gcd(a[i - 1], a[i]);
        } 
        else {
            long long left_gcd = gcd(a[i - 1], a[i]);
            long long right_gcd = gcd(a[i], a[i + 1]);
            
            required_multiple = lcm(left_gcd, right_gcd);
        }

        if (required_multiple < a[i]) {
            operations++;
        }
    }

    cout << operations << endl;
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