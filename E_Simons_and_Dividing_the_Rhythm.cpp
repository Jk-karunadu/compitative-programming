#include <iostream>
#include <vector>

using namespace std;

static const int MOD = 998244353;

vector<int> memo;
vector<int> arr;
int total_n;

int solve_partition(int start_idx) {
    if (start_idx == total_n) return 1;

    if (memo[start_idx] != -1) return memo[start_idx];

    long long current_ways = 0;
    int remaining_len = total_n - start_idx;
    
    vector<int> pi(remaining_len, 0);

    for (int j = 0; j < remaining_len; j++) {
        if (j > 0) {
            int k = pi[j - 1];
            while (k > 0 && arr[start_idx + j] != arr[start_idx + k]) {
                k = pi[k - 1];
            }
            if (arr[start_idx + j] == arr[start_idx + k]) {
                k++;
            }
            pi[j] = k;
        }

        if (pi[j] == 0) {
            current_ways = (current_ways + solve_partition(start_idx + j + 1)) % MOD;
        }
    }

    return memo[start_idx] = (int)current_ways;
}

void run_test_case() {
    int n;
    if (!(cin >> n)) return;
    
    total_n = n;
    arr.assign(n, 0);
    for (int i = 0; i < n; i++) cin >> arr[i];

    memo.assign(n + 1, -1);

    cout << solve_partition(0) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        run_test_case();
    }
    return 0;
}