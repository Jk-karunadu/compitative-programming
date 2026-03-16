#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int x, y, n;
        cin >> x >> y >> n;

        int current_rem = n % x;

        if (current_rem >= y) {
            cout << n - (current_rem - y) << "\n";
        } else {
            cout << n - (current_rem + x - y) << "\n";
        }
    }

    return 0;
}