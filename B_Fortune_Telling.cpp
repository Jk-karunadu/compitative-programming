#include <iostream>
#include <vector>

using namespace std;

void identify_fortune_teller() {
    int n;
    long long alice_start, target_y;
    if (!(cin >> n >> alice_start >> target_y)) return;

    long long array_parity_sum = 0;
    for (int i = 0; i < n; ++i) {
        long long val;
        cin >> val;
        array_parity_sum += val;
    }

    
    bool alice_final_parity = (alice_start + array_parity_sum) % 2;
    bool target_parity = target_y % 2;

    if (alice_final_parity == target_parity) {
        cout << "Alice" << endl;
    } else {
        cout << "Bob" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test_queries;
    if (!(cin >> test_queries)) return 0;
    
    while (test_queries--) {
        identify_fortune_teller();
    }
    
    return 0;
}