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

    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    vector<long long> pref(n + 1, 0);
    for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + b[i];
    }

    long long max_score = 0;

    for (int i = 0; i < n; i++) {
        long long x = a[i];
        long long available_swords = n - i;
        auto it = upper_bound(pref.begin(), pref.end(), available_swords);
        int k = distance(pref.begin(), it) - 1;
        max_score = max(max_score, x * k);
        while (i + 1 < n && a[i + 1] == a[i]) {
            i++;
        }
    }

    cout << max_score << "\n";
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