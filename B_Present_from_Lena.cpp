#include <iostream>
using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;

   
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < n - i; j++) cout << "  "; 
        bool first = true;
        for (int k = 0; k <= i; k++) {
            if (!first) cout << " ";
            cout << k;
            first = false;
        }
        for (int l = i - 1; l >= 0; l--) {
            cout << " " << l;
        }
        cout << '\n';
    }

   
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < n - i; j++) cout << "  ";
        bool first = true;
        for (int k = 0; k <= i; k++) {
            if (!first) cout << " ";
            cout << k;
            first = false;
        }
        for (int l = i - 1; l >= 0; l--) {
            cout << " " << l;
        }
        cout << '\n';
    }

    return 0;
}
