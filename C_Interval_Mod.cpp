#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
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
#define debug(x) cerr << #x <<" = "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.fi); cerr << ","; _print(p.se); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}


ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll power(ll a, ll b, ll m = MOD) {
    ll res = 1; a %= m;
    while (b > 0) {
        if (b & 1) res = res * a % m;
        a = a * a % m; b >>= 1;
    }
    return res;
}

int m = 1e9 + 7;
    vector<long long> f, inf;

    ll modex(ll base, ll exp) {
        ll res = 1;
        while (exp) {
            if (exp & 1)
                res = (res * base) % m;
            base = (base * base) % m;
            exp >>= 1;
        }

        return res;
    }

    void  precom(int n) {
        f.resize(n + 1);
        inf.resize(n + 1);
        f[0] = 1;
        for (int i = 1; i <= n; i++) {
            f[i] = (f[i - 1] * i) % m;
        }

        inf[n] = modex(f[n], m - 2);

        for (int i = n - 1; i >= 0; i--) {
            inf[i] = (inf[i + 1] * (i + 1)) % m;
        }
    }

    ll ncr(int n, int r) {
        if (r < 0 || r > n)
            return 0;

        return (f[n] * inf[r] % m * inf[n - r] % m) % m;
    }



void solve() {
    int n, k, p, q;
    if (!(cin >> n >> k >> p >> q)) return;

    vector<int> a(n), b(n);
    vector<ll> pref(n);

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[i] = x % min(p, q);
        b[i] = (x % max(p, q)) % min(p, q);

        pref[i] = min(a[i], b[i]);
        if (i > 0) pref[i] += pref[i - 1];
    }

    vector<ll> suff(n);
    suff[n - 1] = min(a[n - 1], b[n - 1]);
    for (int i = n - 2; i >= 0; i--) {
        suff[i] = min(a[i], b[i]);
        suff[i] += suff[i + 1];
    }
    ll suma = accumulate(a.begin(), a.begin() + k, 0LL);
    ll sumb = accumulate(b.begin(), b.begin() + k, 0LL);
    ll ans = min(suma, sumb) + ((k < n) ? suff[k] : 0);
    for (int i = k; i < n; i++) {
        suma += a[i] - a[i - k];
        sumb += b[i] - b[i - k];
        
        ll current_val = pref[i - k] + min(suma, sumb) + ((i + 1 < n) ? suff[i + 1] : 0);
        ans = min(ans, current_val);
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    if (!(cin >> tc)) return 0;
    while (tc--) {
        solve();
    }
    return 0;
}