#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;
    map<int, long long> sums;
    
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        sums[val - i] += val;
    }

    long long max_sum = 0;
    for (auto const& [key, total] : sums) {
        max_sum = max(max_sum, total);
    }

    cout << max_sum << endl;

    return 0;
}