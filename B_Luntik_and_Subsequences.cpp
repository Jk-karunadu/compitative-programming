#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;

        long long zero_count = 0, one_count = 0;
        for (int i = 0; i < n; i++) {
            long long x;
            cin >> x;
            if (x == 0) zero_count++;
            if (x == 1) one_count++;
        }

        
        cout << one_count * (1LL << zero_count) << "\n";
    }
    return 0;
}
