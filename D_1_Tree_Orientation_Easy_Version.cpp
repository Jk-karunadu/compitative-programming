#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool solve() {
    int n;
    cin >> n;
    vector<string> s(n);
    vector<vector<int>> reach(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        for (int j = 0; j < n; j++) {
            reach[i][j] = s[i][j] - '0';
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j && reach[i][j] && reach[j][i]) return false;
        }
    }

    vector<pair<int, int>> edges;
    for (int u = 0; u < n; u++) {
        for (int v = 0; v < n; v++) {
            if (u == v || !reach[u][v]) continue;

            bool intermediate = false;
            for (int w = 0; w < n; w++) {
                if (w != u && w != v && reach[u][w] && reach[w][v]) {
                    intermediate = true;
                    break;
                }
            }
            if (!intermediate) {
                edges.push_back({u + 1, v + 1});
            }
        }
    }

    if (edges.size() != n - 1) return false;
    vector<vector<int>> dist(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) dist[i][i] = 1;
    for (auto& e : edges) dist[e.first - 1][e.second - 1] = 1;

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] |= (dist[i][k] & dist[k][j]);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] != reach[i][j]) return false;
        }
    }

    vector<int> parent(n + 1);
    for (int i = 1; i <= n; i++) parent[i] = i;
    auto find = [&](auto self, int i) -> int {
        return (parent[i] == i) ? i : (parent[i] = self(self, parent[i]));
    };

    int components = n;
    for (auto& e : edges) {
        int rootX = find(find, e.first);
        int rootY = find(find, e.second);
        if (rootX != rootY) {
            parent[rootX] = rootY;
            components--;
        }
    }

    if (components != 1) return false;

    cout << "Yes" << endl;
    for (auto& e : edges) {
        cout << e.first << " " << e.second << endl;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        if (!solve()) {
            cout << "No" << endl;
        }
    }
    return 0;
}