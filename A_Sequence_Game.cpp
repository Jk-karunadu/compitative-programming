#include <bits/stdc++.h>
using namespace std;

int main() {
   

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        long long mn = LLONG_MAX;
        long long mx = LLONG_MIN;

        for (int i = 0; i < n; i++) {
            long long x;
            cin >> x;

           
            if (x < mn) mn = x;
            if (x > mx) mx = x;
        }

        long long target;
        cin >> target;

        if (target >= mn && target <= mx)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
