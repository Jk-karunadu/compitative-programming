#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long a, b;
        cin >> a >> b;

      
        if (a > b) swap(a, b);

       
        if (a == b) {
            cout << 0 << "\n";
            continue;
        }

       
        if (b % a != 0) {
            cout << -1 << "\n";
            continue;
        }

        long long ratio = b / a;
        int count = 0;

      
        while (ratio % 2 == 0) {
            ratio /= 2;
            count++;
        }

       
        if (ratio != 1) {
            cout << -1 << "\n";
            continue;
        }

        
        int ans = (count + 2) / 3; 
        cout << ans << "\n";
    }

    return 0;
}
