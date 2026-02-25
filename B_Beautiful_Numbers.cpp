#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    if (!(cin >> s)) return;

    long long current_sum = 0;
    vector<int> digits;

    for (int i = 0; i < s.length(); i++) {
        int d = s[i] - '0';
        current_sum += d;
        
        if (i == 0) {
            digits.push_back(d - 1); 
        } else {
            digits.push_back(d - 0);
        }
    }

    sort(digits.rbegin(), digits.rend());

    int moves = 0;
    int i = 0;
    while (current_sum > 9 && i < digits.size()) {
        current_sum -= digits[i];
        moves++;
        i++;
    }

    cout << moves << endl;
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