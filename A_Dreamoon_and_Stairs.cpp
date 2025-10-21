#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int minMoves = (n + 1) / 2; // ceil(n/2)
    int ans = -1;
    for (int i = minMoves; i <= n; i++) {
        if (i % m == 0) {
            ans = i;
            break;
        }
    }

    cout << ans << "\n";
    return 0;
}
