#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n, kmax;
        cin >> n >> kmax;

        string s, t;
        cin >> s >> t;

        vector<int> dist(n, 0);
        vector<int> last(26, -1);
        bool possible = true;
        int k = 0;

        for (int i = 0; i < n; i++) {
            last[s[i] - 'a'] = i;  // record rightmost occurrence of s[i] up to i
            int j = last[t[i] - 'a'];
            if (j == -1) { // can't make t[i]
                possible = false;
                break;
            }
            dist[i] = i - j;
            k = max(k, dist[i]);
        }

        if (!possible || k > kmax) {
            cout << -1 << "\n";
            continue;
        }

        cout << k << "\n";
        string cur = s;

        for (int step = 1; step <= k; step++) {
            string nxt = cur;
            for (int i = 1; i < n; i++) {
                // Only propagate if still needs movement
                if (dist[i] >= step) {
                    nxt[i] = cur[i - 1];
                } else {
                    nxt[i] = cur[i];
                }
            }
            cur = nxt;
            cout << cur << "\n";
        }
    }
}
