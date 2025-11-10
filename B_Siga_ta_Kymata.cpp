#include <bits/stdc++.h>
#include <climits>

using namespace std;

pair<int, int> find_operation_bounds(
    const vector<int>& permutation, int n,
    int start_target_pos, int end_target_pos,
    int range_min, int range_max,
    bool case1_ok, bool case2_ok) 
{
    int operation_l = -1;
    int operation_r = -1;

    if (case1_ok) {
       
        int l_search_idx = 1;
        while (l_search_idx < start_target_pos) {
            if (permutation[l_search_idx] < range_min) {
                operation_l = l_search_idx;
                break;
            }
            l_search_idx++;
        }
       
        int r_search_idx = end_target_pos + 1;
        while (r_search_idx <= n) {
            if (permutation[r_search_idx] > range_max) {
                operation_r = r_search_idx;
                break;
            }
            r_search_idx++;
        }
    } else if (case2_ok) {
       
        int l_search_idx = 1;
        while (l_search_idx < start_target_pos) {
            if (permutation[l_search_idx] > range_max) {
                operation_l = l_search_idx;
                break;
            }
            l_search_idx++;
        }
    
        int r_search_idx = end_target_pos + 1;
        while (r_search_idx <= n) {
            if (permutation[r_search_idx] < range_min) {
                operation_r = r_search_idx;
                break;
            }
            r_search_idx++;
        }
    }
    return {operation_l, operation_r};
}


void solve() {
    int n;
    cin >> n;

    vector<int> permutation(n + 1);
    int i = 1;
    while (i <= n) {
        cin >> permutation[i];
        i++;
    }
    
    string target_string;
    cin >> target_string;

    bool is_impossible = false;
    vector<int> target_indices; 
    
    i = 1;
    while (i <= n) {
        if (target_string[i - 1] == '1') {
            if (i == 1 || i == n) {
                is_impossible = true;
            }
            target_indices.push_back(i);
        }
        i++;
    }

    if (is_impossible) {
        cout << -1 << "\n";
        return;
    }

    int num_targets = target_indices.size();
    if (num_targets == 0) {
        cout << 0 << "\n";
        return;
    }

    
    vector<int> target_values(num_targets + 1);
    i = 1;
    while (i <= num_targets) {
        target_values[i] = permutation[target_indices[i - 1]];
        i++;
    }

   
    vector<int> prefix_min(n + 1, INT_MAX);
    vector<int> prefix_max(n + 1, -1);
    prefix_min[0] = INT_MAX;
    prefix_max[0] = -1;
    i = 1;
    while (i <= n) {
        prefix_min[i] = min(prefix_min[i - 1], permutation[i]);
        prefix_max[i] = max(prefix_max[i - 1], permutation[i]);
        i++;
    }

    vector<int> suffix_min(n + 2, INT_MAX);
    vector<int> suffix_max(n + 2, -1);
    suffix_min[n + 1] = INT_MAX;
    suffix_max[n + 1] = -1;
    i = n;
    while (i >= 1) {
        suffix_min[i] = min(suffix_min[i + 1], permutation[i]);
        suffix_max[i] = max(suffix_max[i + 1], permutation[i]);
        i--;
    }

   
    vector<int> left_min(num_targets + 1), left_max(num_targets + 1);
    vector<int> right_min(num_targets + 1), right_max(num_targets + 1);

    int j = 1;
    while (j <= num_targets) {
        int pos = target_indices[j - 1];
        int left_edge = pos - 1;
        left_min[j] = prefix_min[left_edge];
        left_max[j] = prefix_max[left_edge];
        j++;
    }

    int k = 1;
    while (k <= num_targets) {
        int pos = target_indices[k - 1];
        int right_edge = pos + 1;
        right_min[k] = suffix_min[right_edge];
        right_max[k] = suffix_max[right_edge];
        k++;
    }

   
    vector<pair<int, int>> found_operations;
    int targets_covered = 0; 
    int operation_count = 0;
    bool is_possible = true;

    while (targets_covered < num_targets && is_possible) {
        operation_count++;
        if (operation_count > 5) {
            is_possible = false;
            break;
        }

        int start_range_index = targets_covered + 1;
        int range_min_val = target_values[start_range_index];
        int range_max_val = target_values[start_range_index];
        
        int best_end_range_index = -1;
        int best_range_min_val = 0;
        int best_range_max_val = 0;

       
        int current_end_range_index = start_range_index;
        while (current_end_range_index <= num_targets) {
            bool is_coverable = (left_min[start_range_index] < range_min_val && right_max[current_end_range_index] > range_max_val) ||
                                (left_max[start_range_index] > range_max_val && right_min[current_end_range_index] < range_min_val);
            
            if (is_coverable) {
                best_end_range_index = current_end_range_index;
                best_range_min_val = range_min_val;
                best_range_max_val = range_max_val;
            }

            if (current_end_range_index < num_targets) {
                range_min_val = min(range_min_val, target_values[current_end_range_index + 1]);
                range_max_val = max(range_max_val, target_values[current_end_range_index + 1]);
            }
            current_end_range_index++;
        }

        if (best_end_range_index == -1) {
            is_possible = false;
            break;
        }

        
        int start_target_pos = target_indices[start_range_index - 1];
        int end_target_pos = target_indices[best_end_range_index - 1];

        bool case1_ok = (left_min[start_range_index] < best_range_min_val && right_max[best_end_range_index] > best_range_max_val);
        bool case2_ok = (left_max[start_range_index] > best_range_max_val && right_min[best_end_range_index] < best_range_min_val);

        pair<int, int> operation = find_operation_bounds(
            permutation, n, start_target_pos, end_target_pos,
            best_range_min_val, best_range_max_val,
            case1_ok, case2_ok
        );

        found_operations.push_back(operation);
        targets_covered = best_end_range_index;
    }

   
    if (is_possible && targets_covered >= num_targets) {
        cout << operation_count << "\n";
        
        int op_idx = 0;
        while (op_idx < found_operations.size()) {
            cout << found_operations[op_idx].first << " " << found_operations[op_idx].second << "\n";
            op_idx++;
        }
    } else {
        cout << -1 << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int num_test_cases;
    cin >> num_test_cases;
    
    while (num_test_cases--) {
        solve();
    }
    
    return 0;
}