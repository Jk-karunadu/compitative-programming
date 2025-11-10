#include <bits/stdc++.h>
using namespace std;

int ask_query(int l, int r) {
    cout << "? " << l << " " << r << endl;
   
    int mex_result;
    cin >> mex_result;
    return mex_result;
}


void solve() {
    int n, num_ranges;
    cin >> n >> num_ranges;

    vector<pair<int, int>> given_ranges(num_ranges);
    
    int i = 0;
    while (i < num_ranges) {
        cin >> given_ranges[i].first >> given_ranges[i].second;
        i++;
    }

    int max_mex_found = 0;
    
   
    int range_index = 0;
    while (range_index < num_ranges) {
        pair<int, int> current_range = given_ranges[range_index];
        int current_mex = ask_query(current_range.first, current_range.second);
        max_mex_found = max(max_mex_found, current_mex);
        range_index++;
    }

   
    cout << "! " << max_mex_found << endl;
   
}

int main() {
   
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int num_test_cases;
    cin >> num_test_cases;
    
    while (num_test_cases--) {
        solve();
    }
    
    return 0;
}