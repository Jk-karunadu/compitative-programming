#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<vector<int>> adj;
vector<int> d, s;
vector<long long> v; 

void dfs(int x, int p) {
    s[x] = 0; 
    for (auto y : adj[x]) {
        if (y == p) continue;
        d[y] = d[x] + 1;
        dfs(y, x);
        s[x] += (s[y] + 1); 
    }
    v.push_back(d[x] - s[x]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    if (!(cin >> n >> k)) return 0;
    adj.assign(n, vector<int>());
    d.assign(n, 0);
    s.assign(n, 0);
    v.clear();

    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(0, -1);

    sort(v.rbegin(), v.rend());

    long long ans = 0;
    for (int i = 0; i < k; i++) {
        ans += v[i];
    }

    cout << ans << "\n";

    return 0;
}