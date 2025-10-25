#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k, x;
        cin >> n >> k >> x;

        if (x != 1) {
            // We can always use 1’s to form n
            cout << "YES" << endl;
            cout << n << endl;
            for (int i = 0; i < n; i++) cout << 1 << " ";
            cout << endl;
        } 
        else {
            // x == 1 is forbidden
            if (k == 1) {
                // No numbers available
                cout << "NO" << endl;
            } 
            else if (k == 2) {
                if (n % 2 != 0) cout << "NO" << endl;
                else {
                    cout << "YES" << endl;
                    cout << n / 2 << endl;
                    for (int i = 0; i < n / 2; i++) cout << 2 << " ";
                    cout << endl;
                }
            } 
            else {
                // We can use 2 and 3 to make any number >= 2
                cout << "YES" << endl;
                if (n % 2 == 0) {
                    cout << n / 2 << endl;
                    for (int i = 0; i < n / 2; i++) cout << 2 << " ";
                    cout << endl;
                } else {
                    cout << (n - 3) / 2 + 1 << endl;
                    for (int i = 0; i < (n - 3) / 2; i++) cout << 2 << " ";
                    cout << 3 << endl;
                }
            }
        }
    }
    return 0;
}
