#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        long long q;
        cin >> n >> k >> q;

        vector<long long> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        long long ans = 0;
        long long count = 0; 

        for (int i = 0; i < n; i++) {
            if (a[i] <= q)
                count++;
            else {
                if (count >= k) {
                    long long x = count - k + 1;
                    ans += x * (x + 1) / 2;
                }
                count = 0;
            }
        }

      
        if (count >= k) {
            long long x = count - k + 1;
            ans += x * (x + 1) / 2;
        }

        cout << ans << "\n";
    }

    return 0;
}
