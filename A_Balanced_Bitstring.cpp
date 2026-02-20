#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    bool possible = true;
    for (int i = 0; i < k; i++) {
        char required = '?';
        for (int j = i; j < n; j += k) {
            if (s[j] != '?') {
                if (required != '?' && s[j] != required) { 
                    possible = false;
                    break;
                }
                required = s[j];
            }
        }
        if (!possible) break;
        
        if (required != '?') {
            s[i] = required;
        }
    }

    if (!possible) {
        cout << "NO" << "\n";
        return;
    }

    int cnt0 = 0, cnt1 = 0;
    for (int i = 0; i < k; i++) {
        if (s[i] == '0') cnt0++;
        else if (s[i] == '1') cnt1++;
    }

    if (cnt0 <= k / 2 && cnt1 <= k / 2) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}