#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string s;
    cin >> s;

    long long current_w = 0;
    long long total_w = 0;
    long long ans = 0;
    for (int i = 1; i < s.length(); i++) {
        if (s[i] == 'v' && s[i-1] == 'v') {
            total_w++;
        }
    }

    for (int i = 1; i < s.length(); i++) {
        if (s[i] == 'v' && s[i-1] == 'v') {
            current_w++;
        } else if (s[i] == 'o') {
            ans += current_w * (total_w - current_w);
        }
    }

    cout << ans << endl;

    return 0;
}