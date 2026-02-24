#include <iostream>
#include <vector>
#include <queue>

using namespace std;

long long MOD = 1e9 + 7;

long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

int bfs(int start, vector<bool> &vis, vector<vector<pair<int, int>>> &adj) {
    queue<int> q;
    q.push(start);
    vis[start] = true;
    int count = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        count++;

        for (auto &edge : adj[u]) {
            int v = edge.first;
            int color = edge.second;
            if (color == 0 && !vis[v]) {
                vis[v] = true;
                q.push(v);
            }
        }
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    if (!(cin >> n >> k)) return 0;

    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v, x;
        cin >> u >> v >> x;
        adj[u].push_back({v, x});
        adj[v].push_back({u, x});
    }

    long long total = power(n, k);
    long long bad_sequences = 0;

    vector<bool> vis(n + 1, false);

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            long long component_size = bfs(i, vis, adj);
            bad_sequences = (bad_sequences + power(component_size, k)) % MOD;
        }
    }

    long long ans = (total - bad_sequences + MOD) % MOD;

    cout << ans << endl;

    return 0;
}