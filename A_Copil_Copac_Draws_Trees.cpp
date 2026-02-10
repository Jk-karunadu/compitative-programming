#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> adj[200005];
int dp[200005];      
int edge_idx[200005]; 

void dfs(int u, int p, int last_edge_idx, int current_reading) {
    dp[u] = current_reading;
    edge_idx[u] = last_edge_idx;

    for (auto &edge : adj[u]) {
        int v = edge.first;
        int idx = edge.second;

        if (v == p) continue;

        if (idx < last_edge_idx) {
            dfs(v, u, idx, current_reading + 1);
        } else {
            dfs(v, u, idx, current_reading);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        for (int i = 1; i <= n; i++) adj[i].clear();

        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back({v, i});
            adj[v].push_back({u, i});
        }

        dfs(1, 0, 0, 1);

        int max_readings = 0;
        for (int i = 1; i <= n; i++) {
            max_readings = max(max_readings, dp[i]);
        }
        cout << max_readings << "\n";
    }
    return 0;
}