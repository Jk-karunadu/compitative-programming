#include <iostream>
#include <vector>

using namespace std;

struct Operation {
    int pos;
    long long val;
};

void solve() {
    int n, m;
    long long h;
    cin >> n >> m >> h;

    vector<long long> original(n);
    for (int i = 0; i < n; i++) cin >> original[i];

    vector<Operation> ops(m);
    for (int i = 0; i < m; i++) {
        cin >> ops[i].pos >> ops[i].val;
    }

    vector<long long> current_vals = original;
    // To avoid O(N) resets, we track which indices we actually modified
    vector<int> modified_indices;
    int last_crash_idx = -1;

    for (int i = 0; i < m; i++) {
        int idx = ops[i].pos - 1;
        long long add = ops[i].val;

        if (current_vals[idx] + add > h) {
            // CRASH DETECTED
            last_crash_idx = i;
            
            // Instead of current_vals = original (O(N)), 
            // we only reset the indices we changed (O(number of changes)).
            for (int mod_idx : modified_indices) {
                current_vals[mod_idx] = original[mod_idx];
            }
            modified_indices.clear();
        } else {
            current_vals[idx] += add;
            modified_indices.push_back(idx);
        }
    }

    // After finding the last crash, build the final array from original
    for (int i = last_crash_idx + 1; i < m; i++) {
        int idx = ops[i].pos - 1;
        original[idx] += ops[i].val;
    }

    for (int i = 0; i < n; i++) {
        cout << original[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    // Fast I/O is essential for 2*10^5 inputs
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}