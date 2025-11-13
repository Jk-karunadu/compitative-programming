#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        long long k;
        cin >> n >> k;

        vector<long long> a(n);
        set<long long> s; // Use a set for O(log N) lookups

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            s.insert(a[i]); // Add element to the set
        }
        
        bool found = false;

        if (k == 0) {
           
            if (s.size() < n) {
                found = true;
            }
        } else {
           
            for (int i = 0; i < n; i++) {
                if (s.count(a[i] + k)) {
                    found = true;
                    break;
                }
            }
        }

        if (found) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    return 0;
}