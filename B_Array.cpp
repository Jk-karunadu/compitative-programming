#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < n; i++) {
        vector<pair<double, int>> events;
        int current_count = 0;
        int possible_j = 0;

        for (int j = i + 1; j < n; j++) {
            if (a[i] == a[j]) continue;
            
            possible_j++;
            double mid = (double)(a[i] + a[j]) / 2.0;

            if (a[j] > a[i]) {
                events.push_back({mid + 0.0000001, 1}); 
            } else {
                current_count++;
                events.push_back({mid - 0.0000001, -1});
            }
        }

        sort(events.begin(), events.end());

        int max_j = current_count;
        for (auto& event : events) {
            current_count += event.second;
            max_j = max(max_j, current_count);
        }

        cout << max_j << (i == n - 1 ? "" : " ");
    }
    cout << endl;
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
