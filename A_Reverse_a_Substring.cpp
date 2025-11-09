#include <bits/stdc++.h>
using namespace std;

int get_nextlesser(int i, string s) {
    for (int k = i + 1; k < s.length(); k++) {
        if (s[i] > s[k]) {
            return k;
        }
    }
    return -1;
}

int get_nextgreater(string s) {
    for (int i = 0; i < s.length() - 1; i++) {
        if (s[i] > s[i + 1]) {
            return i;
        }
    }
    return -1;
}

int main() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    int i = get_nextgreater(s);

    if (i == -1) {
        cout << "NO\n";
    } else {
        int j = get_nextlesser(i, s);
        if (j == -1) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            cout << i + 1 << " " << j + 1 << "\n";
        }
    }

    return 0;
}


