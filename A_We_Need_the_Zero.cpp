#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int xr = 0;
        int temp = n; 

        while (n--) {
            int x;
            cin >> x;
            xr ^= x;
        }

        if (temp % 2 == 0 && xr != 0) {
            cout << -1 << endl;
        } else {
            cout << xr << endl;
        }
    }

    return 0;
}
