#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void run() {
    int n;
    long long p, k;
    if (!(cin >> n >> p >> k)) return;

    vector<long long> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];

    sort(v.begin(), v.end());

    for (auto val : v) {
        if (val > p) break;
        long long d = min(k, p - val);
        k -= d;
        p += (val + d);
    }

    cout << p << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) run();
    
    return 0;
}