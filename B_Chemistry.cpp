#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        unordered_map<char, int> m;
        for (char c : s) {
            m[c]++;
        }

        int oddCount = 0;
        for (auto &p : m) {
            if (p.second % 2 != 0) {
                oddCount++;
            }
        }

       
        if (oddCount - k <= 1) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
