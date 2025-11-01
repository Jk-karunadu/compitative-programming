#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int digits = 0;
        int temp = n;
        while (temp >= 10) {
            temp /= 10;
            digits++;
        }

      
        int count = digits * 9 + temp;
        cout << count << endl;
    }
    return 0;
}
