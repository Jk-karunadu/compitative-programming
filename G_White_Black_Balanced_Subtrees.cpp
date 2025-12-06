#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> parent(n + 1);
    for (int i = 2; i <= n; i++) {
        cin >> parent[i];
    }

    string s;
    cin >> s;
    vector<int> balance(n + 1);
    for (int i = 1; i <= n; i++) {
        if (s[i - 1] == 'W') {
            balance[i] = 1;
        } else {
            balance[i] = -1;
        }
    }

    int balanced_subtrees = 0;
    for (int i = n; i >= 1; i--) {
        if (balance[i] == 0) {
            balanced_subtrees++;
        }
        if (i > 1) {
            balance[parent[i]] += balance[i];
        }
    }

    cout << balanced_subtrees << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}