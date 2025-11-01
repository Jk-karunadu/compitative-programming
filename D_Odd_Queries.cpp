#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, q;
        cin >> n >> q;

        vector<long long> vec(n);
        for (int i = 0; i < n; i++) {
            cin >> vec[i];
        }

       
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + vec[i];
        }

        while (q--) {
            long long l, r, k;
            cin >> l >> r >> k;

          
            long long totalSum = prefix[n];

            
            long long oldSum = prefix[r] - prefix[l - 1];

           
            long long newSum = totalSum - oldSum + (r - l + 1) * k;

            if (newSum % 2 != 0)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }

    return 0;
}
