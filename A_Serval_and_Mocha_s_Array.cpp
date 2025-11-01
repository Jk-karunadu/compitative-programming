#include <bits/stdc++.h>
using namespace std;

int main() {
 
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        bool possible = false;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (__gcd(a[i], a[j]) <= 2) {
                    possible = true;
                    break;
                }
            }
            if (possible) break;
        }

        cout << (possible ? "YES\n" : "NO\n");
    }
}
