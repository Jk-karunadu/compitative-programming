#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int test_cases;
    if (!(cin >> test_cases)) return 0;

    while (test_cases--) {
        int length;
        string pattern;
        cin >> length >> pattern;

        if ((length % 2 != 0) && pattern[0] == 'b') {
            cout << "NO\n";
            continue;
        }

        bool is_possible = true;
        for (int i = (length % 2); i < length; i += 2) {
            if (pattern[i] != '?' && pattern[i + 1] != '?' && pattern[i] == pattern[i + 1]) {
                is_possible = false;
                break;
            }
        }

        if (is_possible) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}