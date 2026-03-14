#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<pair<double, double>> tasks(n);
    for (int i = 0; i < n; i++) {
        cin >> tasks[i].first >> tasks[i].second;
    }

    double max_val = 0;
    for (int i = n - 1; i >= 0; i--) {
        double ci = tasks[i].first;
        double pi = tasks[i].second;
        double multiplier = (100.0 - pi) / 100.0;
        
        max_val = max(max_val, ci + multiplier * max_val);
    }

    cout << fixed << setprecision(10) << max_val << endl;
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