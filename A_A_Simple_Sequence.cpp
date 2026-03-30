#include <bits/stdc++.h>

using namespace std;

// Speed optimization
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl '\n'

// Shorthands
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

// Loops
#define for0(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define for1(i, n) for (ll i = 1; i <= (ll)(n); ++i)
#define forr(i, n) for (ll i = (ll)(n) - 1; i >= 0; --i)
#define fora(i, a, b) for (ll i = (ll)(a); i <= (ll)(b); ++i)

const int MOD = 1e9 + 7;
const ll INF = 1e18;

// Debugging
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

// Math Utilities
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

ll modex(ll base, ll exp) {
    ll res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp & 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return res;
}

// Combinatorics
vector<long long> f, inf;

void precom(int n) {
    f.assign(n + 1, 1);
    inf.assign(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        f[i] = (f[i - 1] * i) % MOD;
    }
    inf[n] = modex(f[n], MOD - 2);
    for (int i = n - 1; i >= 0; i--) {
        inf[i] = (inf[i + 1] * (i + 1)) % MOD;
    }
}

ll ncr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return (f[n] * inf[r] % MOD * inf[n - r] % MOD) % MOD;
}

// Logic
void solve() {
   int n;
    if (!(cin >> n)) return;
    
    for (int i = n; i >= 1; i--) {
        cout << i << (i == 1 ? "" : " ");
    }
    cout << endl;
}

int main() {
    fast_io;
    int t = 1;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}