#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>

using namespace std;
vector<int> get_divisors(int g, int n) {
    if (g == 0) {
        vector<int> all_k;
        for (int i = 1; i <= n; ++i) {
            all_k.push_back(i);
        }
        return all_k;
    }

    vector<int> divisors;
    for (int i = 1; i * i <= g; ++i) {
        if (g % i == 0) {
            divisors.push_back(i);
            if (i * i != g) {
                divisors.push_back(g / i);
            }
        }
    }
    sort(divisors.begin(), divisors.end());
    return divisors;
}

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> bit_counts(30, 0); 
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        for (int j = 0; j < 30; ++j) {
            if ((a[i] >> j) & 1) {
                bit_counts[j]++;
            }
        }
    }
    int final_gcd = 0;
    
    for (int count : bit_counts) {
        if (count > 0) {
            if (final_gcd == 0) {
                final_gcd = count;
            } else {
                final_gcd = __gcd(final_gcd, count);
            }
        }
    }
    vector<int> possible_k = get_divisors(final_gcd, n);
    for (size_t i = 0; i < possible_k.size(); ++i) {
        cout << possible_k[i] << (i == possible_k.size() - 1 ? "" : " ");
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