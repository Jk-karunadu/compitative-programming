#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        bool three = false;
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '.') count++;
            if (i + 2 < n && s[i] == '.' && s[i + 1] == '.' && s[i + 2] == '.') {
                three = true;
            }
        }

        if (three) cout << 2 << endl;
        else cout << count << endl;
    }

    return 0;
}
