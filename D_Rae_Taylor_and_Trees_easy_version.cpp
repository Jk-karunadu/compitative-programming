#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }

    vector<int> suff_max(n);
    suff_max[n - 1] = p[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        suff_max[i] = max(suff_max[i + 1], p[i]);
    }

    int curr_min = INT_MAX;
    
  
    for (int i = 0; i < n - 1; ++i) {
        curr_min = min(curr_min, p[i]);
       
        if (curr_min > suff_max[i + 1]) {
            cout << "No" << endl;
            return;
        }
    }

    cout << "Yes" << endl;
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