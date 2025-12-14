#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

void solve() {
    string s;
    cin >> s;
    
    int n = s.length();
    if (n <= 1) {
        cout << s << "\n";
        return;
    }
    for (int i = 1; i < n; ++i) {
        if (s[i] == s[i - 1]) {
            for (char c = 'a'; c <= 'c'; ++c) {
                if (c == s[i - 1]) {
                    continue;
                }
                
                if (i + 1 < n && c == s[i + 1]) {
                    continue;
                }
                s[i] = c;
                break;
            }
        }
    }

    cout << s << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();

    return 0;
}