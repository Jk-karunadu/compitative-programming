#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int n, m, d;
        cin >> n >> m >> d;

        int K = (d / m) + 1;

        int min_towers = (n + K - 1) / K;

        cout << min_towers << endl;
    }
    return 0;
}