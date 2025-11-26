#include <iostream>
#include <vector>
#include <map>

using namespace std;
int bit_counts[200005]; 

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> nums(n);
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        nums[i].resize(k);
        for (int j = 0; j < k; ++j) {
            cin >> nums[i][j];
            bit_counts[nums[i][j]]++; 
        }
    }
    
    bool possible = false;
    for (int i = 0; i < n; ++i) {
        bool is_redundant = true;
        for (int bit : nums[i]) {
            if (bit_counts[bit] == 1) {
                is_redundant = false;
                break;
            }
        }
        
        if (is_redundant) {
            possible = true;
            break; 
        }
    }
    
    if (possible) cout << "Yes\n";
    else cout << "No\n";
    for (int i = 0; i < n; ++i) {
        for (int bit : nums[i]) {
            bit_counts[bit]--; 
        }
    }
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