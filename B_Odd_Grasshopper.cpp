#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long x0, n;
        cin >> x0 >> n; 

        long long ans = 0;

        if (n % 4 == 1)
            ans = -n;
        else if (n % 4 == 2)
            ans = 1;
        else if (n % 4 == 3)
            ans = n + 1;
        else
            ans = 0;

        if (x0 % 2 == 0)
            cout << x0 + ans << "\n";
        else
            cout << x0 - ans << "\n";
    }

    return 0;
}
