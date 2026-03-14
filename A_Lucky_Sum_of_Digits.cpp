#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;

    int original_n = n;
    string result = "";
    int fours = 0;
    int sevens = 0;

    while (n >= 0) {
        if (n % 7 == 0) {
            sevens = n / 7;
            n = 0;
            break;
        }
        n -= 4;
        fours++;
    }

    if (n == 0) {
        for (int i = 0; i < fours; i++) result += '4';
        for (int i = 0; i < sevens; i++) result += '7';
        cout << result << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}