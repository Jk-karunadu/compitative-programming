#include <iostream>
#include <vector>

using namespace std;

void solve_game() {
    int len;
    cin >> len;
    vector<int> v1(len), v2(len);
    for (int &x : v1) cin >> x;
    for (int &x : v2) cin >> x;

    int xor_sum_1 = 0;
    int xor_sum_2 = 0;
    for (int i = 0; i < len; i++) {
        xor_sum_1 ^= v1[i];
        xor_sum_2 ^= v2[i];
    }
    if (xor_sum_1 == xor_sum_2) {
        cout << "Tie\n";
        return;
    }

    int diff_idx = -1;
    for (int i = len - 1; i >= 0; i--) {
        if (v1[i] != v2[i]) {
            diff_idx = i;
            break;
        }
    }
    if (diff_idx % 2 == 0) {
        cout << "Ajisai\n";
    } else {
        cout << "Mai\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test_cases;
    cin >> test_cases;
    while (test_cases--) {
        solve_game();
    }

    return 0;
}