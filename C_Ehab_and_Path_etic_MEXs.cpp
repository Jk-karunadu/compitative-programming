#include <bits/stdc++.h>

using namespace std;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<vector<pair<int, int>>> adjk(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adjk[u].push_back({v, i});
        adjk[v].push_back({u, i});
    } 

    vector<int> fans(n - 1, -1);
    int k = 0;
    for (int i = 1; i <= n; i++) {
        if (adjk[i].size() >= 3) {
            fans[adjk[i][0].second] = 0;
            fans[adjk[i][1].second] = 1;
            fans[adjk[i][2].second] = 2;
            k = 3;
            break;
        }
    }

    for (int i = 0; i < n - 1; i++) {
        if (fans[i] == -1) {
            fans[i] = k++;
        }
    } 

    for (auto i : fans)
        cout << i << '\n'; 

    return 0;
}
