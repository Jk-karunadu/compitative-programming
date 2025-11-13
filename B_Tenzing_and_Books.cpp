#include <bits/stdc++.h>

using namespace std;

vector<int> read_prefix_ors(int n) {
    vector<int> prefixes;
    prefixes.push_back(0);
    
    int current_or_sum = 0;
    for (int j = 0; j < n; j++) {
        int a;
        cin >> a;
        if ((current_or_sum | a) != current_or_sum) {
            current_or_sum |= a;
            prefixes.push_back(current_or_sum);
        }
    }
    return prefixes;
}

bool solve() {
    int n, x;
    cin >> n >> x;

    vector<int> prefixes_a = read_prefix_ors(n);
    vector<int> prefixes_b = read_prefix_ors(n);
    vector<int> prefixes_c = read_prefix_ors(n);

    for (int A : prefixes_a) {
        if ((A | x) != x) continue; 

        for (int B : prefixes_b) {
            int AB = A | B;
            if ((AB | x) != x) continue;

            for (int C : prefixes_c) {
                if ((AB | C) == x) {
                    return true;
                }
            }
        }
    }
    
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        if (solve()) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}