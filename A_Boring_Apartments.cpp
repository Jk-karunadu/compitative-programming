#include <iostream>
using namespace std;

int main() {  
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;

        int ans = 0;
        int lastdigit = t % 10;

        ans = ans + (lastdigit - 1) * 10; 
        int count = 0;
        int temp = t;
        while (temp) {
            count++;
            temp /= 10;
        }

        ans = ans + count * (count + 1) / 2;
        cout << ans << endl;
    }

    return 0;
}
