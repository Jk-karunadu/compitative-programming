#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int neg = 0; 
        int pos = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x == -1) neg++;
            else pos++;
        }

        int operations = 0;

       
        while (neg > pos) {
            neg--;
            pos++;
            operations++;
        }

       
        if (neg % 2 != 0)
            operations++;

        cout << operations << endl;
    }

    return 0;
}
