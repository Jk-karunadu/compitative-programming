#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        long long a, b, c;
        cin >> a >> b >> c;

        cout << (a < c ? 1 : -1) << " ";
        cout << (c < a * b ? b : -1) << "\n";
    }

    return 0;
}
