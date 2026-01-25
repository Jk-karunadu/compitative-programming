#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;

    vector<int> unique_a;
    vector<int> dist(n + 1, -1);
    vector<bool> exists(n + 1, false);

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        if (val <= n && !exists[val]) {
            exists[val] = true;
            unique_a.push_back(val);
        }
    }

    sort(unique_a.begin(), unique_a.end());

    queue<int> q;
    if (exists[1]) {
        dist[1] = 1;
        q.push(1);
    }

    for (int x : unique_a) {
        if (x > 1) { 
            dist[x] = 1;
            q.push(x);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int x : unique_a) {
            if (x == 1) continue; 
            if (u > n / x) break; 
            
            int next_val = u * x;
            if (next_val <= n && dist[next_val] == -1) {
                dist[next_val] = dist[u] + 1;
                q.push(next_val);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << dist[i] << (i == n ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}