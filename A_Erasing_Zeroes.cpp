#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;

    while (n--) {
        string s;
        cin >> s;

        int first = -1, last = -1;

       
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {
                if (first == -1)
                    first = i;
                last = i;
            }
        }

        if (first == -1 || first == last) {
            cout << 0 << "\n";
            continue;
        }

        int count = 0;
        for (int i = first + 1; i < last; i++) {
            if (s[i] == '0')
                count++;
        }

        cout << count << "\n";
    }
    return 0;
}
