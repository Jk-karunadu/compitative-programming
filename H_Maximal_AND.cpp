#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        long long k;
        cin >> n >> k;

        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        long long ans = 0;

        for (int bit = 30; bit >= 0; bit--) {
            long long cnt = 0;
            for (int i = 0; i < n; i++) {
                if (a[i] & (1LL << bit)) {
                    cnt++;
                }
            }

            long long missing = n - cnt;

            if (missing <= k) {
                ans |= (1LL << bit);
                k -= missing;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
