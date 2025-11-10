#include <bits/stdc++.h>
using namespace std;


void solvePlayerA() {
    int grid_size, true_connectivity;
    cin >> grid_size >> true_connectivity;
    
    vector<string> grid_rows(grid_size);
    for (int i = 0; i < grid_size; ++i) {
        cin >> grid_rows[i];
    }

   
    vector<string> grid_cols(grid_size);
    for (int j = 0; j < grid_size; ++j) {
        string current_col_str = "";
        for (int i = 0; i < grid_size; ++i) {
            current_col_str += grid_rows[i][j];
        }
        grid_cols[j] = current_col_str;
    }

    int selected_row = -1, selected_col = -1;
    bool pair_found = false;

    for (int row_index = 0; row_index < grid_size; ++row_index) {
        for (int col_index = 0; col_index < grid_size; ++col_index) {
            bool is_pair_valid;
            if (true_connectivity == 1) {
               
                is_pair_valid = (grid_rows[row_index] >= grid_cols[col_index]);
            } else {
               
                is_pair_valid = (grid_rows[row_index] < grid_cols[col_index]);
            }

            if (is_pair_valid) {
                selected_row = row_index;
                selected_col = col_index;
                pair_found = true;
                break; 
            }
        }
        if (pair_found) {
            break; 
        }
    }

   
    cout << (selected_row + 1) << " " << (selected_col + 1) << "\n";
}


void solvePlayerB() {
    int grid_size;
    cin >> grid_size;
    string row_string, col_string;
    cin >> row_string >> col_string;
    
   
    cout << (row_string >= col_string ? 1 : 0) << "\n";
}

int main() {
   
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string run_mode;
    cin >> run_mode;

    int num_test_cases;
    cin >> num_test_cases;

    if (run_mode == "first") {
        while (num_test_cases--) {
            solvePlayerA();
        }
    } else {
        while (num_test_cases--) {
            solvePlayerB();
        }
    }
    
    return 0;
}