#include <bits/stdc++.h>

using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl '\n'

#define ll long long
#define vi vector<int>
#define all(v) v.begin(), v.end()

const int MOD = 1e9 + 7;

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

vi p;
vi pref;
int n;


void solve() {
    if (!(cin >> n)) return;
    p.assign(n + 1, 0);
    pref.assign(n + 1, 0);
    
    vi is_safe(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        if (p[i] <= i) is_safe[i] = 1;
    }

    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + is_safe[i];
    }

    int max_chairs = pref[n];

    for (int i = 1; i <= n; i++) {
        if (p[i] > i) {
            
            int current_take = pref[i - 1] + 1 + (pref[p[i] - 1] - pref[i]);
            max_chairs = max(max_chairs, current_take);
        }
    }

    cout << max_chairs << endl;
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