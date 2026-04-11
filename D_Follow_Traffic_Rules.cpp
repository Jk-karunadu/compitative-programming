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
   
}
int main() {
    // Set precision for decimal output as required by the problem
    cout << fixed << setprecision(12);

    double a, v;
    if (!(cin >> a >> v)) return 0;
    double l, d, w;
    cin >> l >> d >> w;

    double total_time = 0;
    double current_speed = 0;

    // Phase 1: Capital to the Speed Sign (Distance d)
    // If the limit w is irrelevant (either too high or physically unreachable)
    if (w >= v || sqrt(2 * a * d) <= w) {
        double time_to_v = v / a;
        double dist_to_v = 0.5 * a * time_to_v * time_to_v;

        if (dist_to_v <= d) {
            // Reaches max speed v before or at distance d
            total_time = time_to_v + (d - dist_to_v) / v;
            current_speed = v;
        } else {
            // Never reaches v, just accelerates for distance d
            current_speed = sqrt(2 * a * d);
            total_time = current_speed / a;
        }
    } else {
        // Must account for speed limit w at distance d
        // We look for a peak speed Vmax between 0 and d
        double v_peak = sqrt((2 * a * d + w * w) / 2.0);

        if (v_peak <= v) {
            // Peak speed is within car limits
            total_time = v_peak / a + (v_peak - w) / a;
        } else {
            // Peak speed would exceed v, so we cap at v and cruise
            double dist_acc = (v * v) / (2.0 * a);
            double dist_dec = (v * v - w * w) / (2.0 * a);
            double dist_cruise = d - dist_acc - dist_dec;
            total_time = (v / a) + (dist_cruise / v) + (v - w) / a;
        }
        current_speed = w;
    }

    // Phase 2: Speed Sign to Bercouver (Distance l - d)
    double remaining_dist = l - d;
    double time_to_v_again = (v - current_speed) / a;
    double dist_to_v_again = current_speed * time_to_v_again + 0.5 * a * time_to_v_again * time_to_v_again;

    if (dist_to_v_again <= remaining_dist) {
        // Accelerates to v and stays there
        total_time += time_to_v_again + (remaining_dist - dist_to_v_again) / v;
    } else {
        // Distance is too short to reach v
        double final_speed = sqrt(current_speed * current_speed + 2 * a * remaining_dist);
        total_time += (final_speed - current_speed) / a;
    }

    cout << total_time << endl;

    return 0;
}