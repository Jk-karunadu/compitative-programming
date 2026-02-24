#include <bits/stdc++.h>
using namespace std;

struct Segment {
    int l, r, id;
};

bool compareSegments(const Segment &a, const Segment &b) {
    if (a.l != b.l) return a.l < b.l;
    return a.r < b.r;
}

void solve() {
    int n;
    cin >> n;
    vector<Segment> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i].l >> p[i].r;
        p[i].id = i;
    }

    sort(p.begin(), p.end(), compareSegments);

    vector<int> ans(n);
    int max_r = p[0].r;
    int split_idx = -1;

    for (int i = 1; i < n; i++) {
        if (p[i].l > max_r) {
            split_idx = i;
            break;
        }
        max_r = max(max_r, p[i].r);
    }

    if (split_idx == -1) {
        cout << -1 << endl;
    } else {
        for (int i = 0; i < n; i++) {
            if (i < split_idx) ans[p[i].id] = 1;
            else ans[p[i].id] = 2;
        }
        
        for (int i = 0; i < n; i++) {
            cout << ans[i] << (i == n - 1 ? "" : " ");
        }
        cout << endl;
    }
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