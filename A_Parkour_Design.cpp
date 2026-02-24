#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            long long x, y;
            cin >> x >> y;
            if ((x - 2 * y) % 3 != 0) {
                cout << "NO\n";
            } else {
                bool isValid = (y >= 0) ? (x >= 2 * y) : (x >= -4 * y);
                cout << (isValid ? "YES\n" : "NO\n");
            }
        }
    }

    return 0;
}