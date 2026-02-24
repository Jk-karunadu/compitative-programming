#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int points = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k == 0) {
                if (k == n) {
                    points++; 
                    continue;
                }

                int g = 0;
                for (int i = 0; i + k < n; i++) {
                    g = __gcd(g, abs(a[i] - a[i + k]));
                }

                if (g != 1) {
                    points++;
                }
            }
        }
        cout << points << endl;
    }
    return 0;
}