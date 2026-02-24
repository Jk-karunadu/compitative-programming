#include <bits/stdc++.h>
using namespace std;

int cuts = 0;

int dfs(int u, int p, vector<int>& vis, vector<vector<int>>& adj) {
    vis[u] = 1;
    int current_subtree_size = 1; 

    for (int v : adj[u]) {
        if (v != p) { 
            int child_subtree_size = dfs(v, u, vis, adj);
            
            if (child_subtree_size % 2 == 0) {
                cuts++;
            } else {
                current_subtree_size += child_subtree_size;
            }
        }
    }
    return current_subtree_size;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    if (n % 2 != 0) {
        cout << -1 << endl;
        return 0;
    }

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<int> vis(n + 1, 0);
    
    dfs(1, -1, vis, adj);

    cout << cuts << endl;

    return 0;
}