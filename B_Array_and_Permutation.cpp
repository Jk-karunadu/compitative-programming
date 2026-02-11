#include <iostream>
#include <vector>

using namespace std;
bool validate_transformation(int length, const vector<int>& original_pos, const vector<int>& target) {
    int previous_value = target[0];
    
    for (int i = 1; i < length; ++i) {
        int current_value = target[i];
        
        if (current_value != previous_value) {
            if (original_pos[current_value] < original_pos[previous_value]) {
                return false;
            }
            previous_value = current_value;
        }
    }
    
    return true;
}

void execute_test_case() {
    int n;
    if (!(cin >> n)) return;

    vector<int> initial_index_map(n + 1);
    for (int i = 1; i <= n; ++i) {
        int val;
        cin >> val;
        initial_index_map[val] = i;
    }

    vector<int> target_sequence(n);
    for (int i = 0; i < n; ++i) {
        cin >> target_sequence[i];
    }

    if (validate_transformation(n, initial_index_map, target_sequence)) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int total_queries;
    if (!(cin >> total_queries)) return 0;
    
    while (total_queries--) {
        execute_test_case();
    }
    
    return 0;
}