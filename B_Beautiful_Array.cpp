#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        long long k, b, s;
        cin >> k >> b >> s;

        vector<long long> vec(n, 0);

        long long base = k * b;
        if (s < base) {
            cout << -1 << '\n';
            continue;
        }

      
        vec[0] = base;
        long long rem = s - base;

       
        for (int i = 0; i < n && rem > 0; i++) {
            long long add = min(rem, k - 1);
            vec[i] += add;
            rem -= add;
        }

        if (rem > 0) {
            cout << -1 << '\n';
        } else {
            for (int i = 0; i < n; i++)
                cout << vec[i] << (i + 1 == n ? '\n' : ' ');
        }
    }
    return 0;
}
