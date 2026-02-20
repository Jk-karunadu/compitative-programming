#include <bits/stdc++.h>
using namespace std;

long long get_seg(int L, const vector<int>& counts) {
    if (L <= 0) return 0;
    long long total = 0;
    for (int s : counts) {
        if (s >= L) {
            total += (s - L + 1);
        }
    }
    return total;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    long long k;
    cin >> n >> m >> k;

    vector<int> a_counts;
    int cur_a = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x == 1) cur_a++;
        else {
            if (cur_a > 0) a_counts.push_back(cur_a);
            cur_a = 0;
        }
    }
    if (cur_a > 0) a_counts.push_back(cur_a);

    vector<int> b_counts;
    int cur_b = 0;
    for (int j = 0; j < m; j++) {
        int x; cin >> x;
        if (x == 1) cur_b++;
        else {
            if (cur_b > 0) b_counts.push_back(cur_b);
            cur_b = 0;
        }
    }
    if (cur_b > 0) b_counts.push_back(cur_b);

    long long ans = 0;

    for (int i = 1; i * i <= k; i++) {
        if (k % i == 0) {
            int h = i;
            int w = k / i;

            if (h <= n && w <= m) {
                ans += get_seg(h, a_counts) * get_seg(w, b_counts);
            }

            if (h != w) {
                if (w <= n && h <= m) {
                    ans += get_seg(w, a_counts) * get_seg(h, b_counts);
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}