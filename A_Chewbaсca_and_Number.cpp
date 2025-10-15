#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;

    string s = to_string(n);

    for (int i = 0; i < s.size(); i++) {
        int d = s[i] - '0';
        int new_d = 9 - d;

        if (i == 0 && new_d == 0) continue;

        if (new_d < d) s[i] = '0' + new_d;
    }

    cout << s << endl;
    return 0;
}
