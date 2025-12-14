#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;
long long countA = 0;
long long countB = 0;
vector<vector<int>> adj;
void dfs_color(int u, int parent, int color) {
    if (color == 1) {
        countA++;
    } else {
        countB++;
    }

    for (int v : adj[u]) {
        if (v != parent) {
            dfs_color(v, u, 3 - color); 
        }
    }
}

void solve() {
    int n;
    if (!(cin >> n)) return;
    if (n <= 1) {
        cout << 0 << "\n";
        return;
    }
    adj.assign(n + 1, vector<int>());
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    countA = 0;
    countB = 0;

    dfs_color(1, 0, 1);
    long long max_possible_edges = countA * countB;
    
    long long initial_edges = n - 1;
    long long max_added_edges = max_possible_edges - initial_edges;

    cout << max_added_edges << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}