#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int last_s = n + 1; 
    int last_t = n + 1;
    int penalty = 0;

    for (int x : a) {
        if (last_s < last_t) swap(last_s, last_t);

        if (x <= last_t) {
            last_t = x;
        } else if (x <= last_s) {
            last_s = x;
        } else {
            penalty++;
            last_t = x;
        }
    }

    cout << penalty << endl;
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

// yes