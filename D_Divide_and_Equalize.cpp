#include <iostream>
#include <vector>
#include <map>

using namespace std;
void add_factors(int num, map<int, int>& counts) {
    for (int i = 2; i * i <= num; ++i) {
        while (num % i == 0) {
            counts[i]++;
            num /= i;
        }
    }
    if (num > 1) {
        counts[num]++;
    }
}
void solve() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    map<int, int> prime_counts;
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        add_factors(a[i], prime_counts);
    }
    for (auto const& entry : prime_counts) {
        if (entry.second % n != 0) {
            cout << "NO" << "\n";
            return;
        }
    }
    
    cout << "YES" << "\n";
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