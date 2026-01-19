#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    a.erase(unique(a.begin(), a.end()), a.end());

    int max_mex = 1;
    int current_streak = 1;

    for (int i = 1; i < a.size(); i++) {
        if (a[i] == a[i - 1] + 1) {
            current_streak++;
        } else {
            max_mex = max(max_mex, current_streak);
            current_streak = 1;
        }
    }
    max_mex = max(max_mex, current_streak);

    cout << max_mex << endl;
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