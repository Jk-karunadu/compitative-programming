#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<int> getPrimeFactors(int n) {
    vector<int> factors;
    if (n <= 1) return factors;
    int temp = n;
    for (int i = 2; i * i <= temp; i++) {
        while (temp % i == 0) {
            factors.push_back(i);
            temp /= i;
        }
    }
    if (temp > 1) factors.push_back(temp);
    return factors;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    bool initially_sorted = true;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i > 0 && a[i] < a[i - 1]) initially_sorted = false;
    }

    if (initially_sorted) {
        cout << "Bob" << endl;
        return;
    }

    int prev_largest_factor = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] == 1) {
            if (prev_largest_factor > 1) {
                cout << "Alice" << endl;
                return;
            }
            prev_largest_factor = 1;
            continue;
        }

        vector<int> factors = getPrimeFactors(a[i]);
        set<int> unique_primes(factors.begin(), factors.end());

        if (unique_primes.size() >= 2) {
            cout << "Alice" << endl;
            return;
        }

        int current_smallest = factors.front();
        
        if (prev_largest_factor > current_smallest) {
            cout << "Alice" << endl;
            return;
        }

        prev_largest_factor = factors.back();
    }

    cout << "Bob" << endl;
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