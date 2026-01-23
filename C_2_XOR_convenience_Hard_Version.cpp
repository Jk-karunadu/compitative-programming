#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>

using namespace std;

void solve() {
    int n;
    cin >> n;

    // Check if n is a power of 2
    if ((n & (n - 1)) == 0) {
        cout << "-1\n";
        return;
    }

    int K = 1;
    while (K <= n) K <<= 1;
    K >>= 1; // Largest power of 2 <= n

    vector<int> p(n + 1);

    // 1. Fixed assignments
    p[n] = K;
    p[n - K] = n;
    p[K] = K + 1;
    p[K + 1] = 1;

    // 2. Pair assignments
    // Indices 2 to n-K-1 mapped to K+2 to n-1
    for (int i = 2; i < n - K; ++i) {
        p[i] = i + K;
        p[i + K] = i;
    }

    // 3. Chain assignment for the "gap"
    // We need to fill indices n-K+1 to K-1 and index 1.
    // The chain flows into K+1 (value 1).
    int current_target_val = 1; // p[K+1]
    
    // Iterate backwards from K-1 down to n-K+1
    for (int i = K - 1; i >= n - K + 1; --i) {
        p[i] = i ^ current_target_val;
        current_target_val = p[i];
    }
    
    // Finally index 1
    p[1] = 1 ^ current_target_val;

    // Output the permutation
    for (int i = 1; i <= n; ++i) {
        cout << p[i] << (i == n ? "" : " ");
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