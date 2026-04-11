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

  int original_t = 0;

void solve() {
    int x, y;
    if (!(cin >> x >> y)) return;

    // FIX 1: Apply the special multitest instruction
    // "If t = 2, add 1 to x". To keep n (x+y) consistent with the tree size,
    // we increment x and decrement y.
    if (original_t == 2) {
        x++;
        y--;
    }

    int n = x + y;

    // FIX 2: Correct NO conditions
    // 1. x > y: Impossible because every even subtree implies at least one odd leaf.
    // 2. n is even and x is 0: Root (size n) must be even, so x must be >= 1.
    // 3. n is odd and y is 0: Root (size n) must be odd, so y must be >= 1.
    if (x > y || (n % 2 == 0 && x == 0) || (n % 2 == 1 && y == 0) || x < 0 || y < 0) {
        cout << "NO" << "\n";
        return;
    }

    cout << "YES" << "\n";

    int num = n;
    int temp_x = x;

    // Account for the root node (node 1)
    if (num % 2 == 0) {
        temp_x--; // Node 1 is even
    }

    // FIX 3: Construction logic
    // Each iteration creates an even subtree (at 'num') by attaching an odd leaf ('num-1').
    // This uses one 'even' count and one 'odd' count.
    while (temp_x > 0 && num > 2) {
        cout << num << " " << num - 1 << "\n"; // num-1 is leaf of num
        cout << num << " " << 1 << "\n";       // num is child of root
        num -= 2;
        temp_x--;
    }

    // Attach all remaining nodes directly to node 1 as leaves (size 1 = odd).
    while (num > 1) {
        cout << num << " " << 1 << "\n";
        num--;
    }
}

int main() {
    // FIX 4: Use fast_io properly and avoid endl
    fast_io;
    int t = 1;
    if (!(cin >> t)) return 0;
    
    original_t = t; // Store the initial t for the special solve rule
    
    while (t--) {
        solve();
    }

    return 0;
}