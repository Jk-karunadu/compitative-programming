#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    if (!(cin >> n >> q)) return 0;

    vector<int> a(n);
    for (int i = 0; i < n; i++) { 
        cin >> a[i];
    }

    vector<long long> diff(n + 1, 0);

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--; 
        r--; 
        diff[l]++;
        if (r + 1 < n + 1) {
            diff[r + 1]--;
        }
    }

    for (int i = 1; i < n; i++) {
        diff[i] += diff[i - 1];
    }

    sort(a.rbegin(), a.rend());
    sort(diff.begin(), diff.begin() + n, greater<long long>());

    long long ans = 0; 
    for (int i = 0; i < n; i++) {
        ans += (long long)a[i] * diff[i];
    }

    cout << ans << endl;

    return 0;
}