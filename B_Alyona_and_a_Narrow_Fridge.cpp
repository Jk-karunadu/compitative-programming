#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
bool can_fit(long long k, long long h, const vector<int>& a) {
    if (k == 0) return true;
    vector<int> subset(a.begin(), a.begin() + k);
    sort(subset.rbegin(), subset.rend());

    long long total_height_needed = 0;
    for (int i = 0; i < k; i += 2) {
        total_height_needed += subset[i];
    }

    return total_height_needed <= h;
}

void solve() {
    int n;
    long long h;
    cin >> n >> h;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int low = 1;
    int high = n;
    int max_k = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (can_fit(mid, h, a)) {
            max_k = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << max_k << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}