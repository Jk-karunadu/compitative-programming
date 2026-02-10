#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> nearestEnemy(n + 1, 0); 
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        nearestEnemy[b] = max(nearestEnemy[b], a);
    }
    
    ll ans = 0;
    int currentLimit = 1; 
    
    for (int i = 1; i <= n; i++) {
        currentLimit = max(currentLimit, nearestEnemy[i] + 1);
        ans += (i - currentLimit + 1);
    }
    
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}