#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }

    if (n <= 2) {
        cout << n << "\n";
        for (int x : p) {
            cout << x << " ";
        }
        cout << "\n";
        return;
    }
    vector<int> s;
    s.push_back(p[0]);
    for (int i = 1; i < n - 1; ++i) {
        bool is_peak = (p[i] > p[i - 1] && p[i] > p[i + 1]);
        bool is_valley = (p[i] < p[i - 1] && p[i] < p[i + 1]);

        if (is_peak || is_valley) {
            s.push_back(p[i]);
        }
    }
    if (s.back() != p[n - 1]) {
        s.push_back(p[n - 1]);
    }
    
    cout << s.size() << "\n";
    for (size_t i = 0; i < s.size(); ++i) {
        cout << s[i] << (i == s.size() - 1 ? "" : " ");
    }
    cout << "\n";
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