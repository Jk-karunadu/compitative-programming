#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<long long> a(n);
        vector<long long> b(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }

        sort(a.begin(), a.end());
        sort(b.rbegin(), b.rend());
        
        long long r = 1;

        for (int i = 0; i < n; i++) {
            long long temp = upper_bound(a.begin(), a.end(), b[i]) - a.begin();
            long long count = a.size() - temp;
            long long choices = max(count - i, 0LL);
            r = (r * choices) % MOD;
        }

        cout << r << "\n";
    }
    return 0;
}