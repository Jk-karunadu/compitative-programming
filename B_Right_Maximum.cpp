#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void solve_fast() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int operations = 0;
    int current_max = -1;

    vector<int> prefix_max(n);
    prefix_max[0] = a[0];
    for(int i = 1; i < n; i++) {
        prefix_max[i] = max(prefix_max[i-1], a[i]);
    }

    int i = n - 1;
    while(i >= 0) {
        int target = prefix_max[i];
        
        operations++;
        
        while(i >= 0 && a[i] < target) {
            i--;
        }
       
        i--; 
    }
    cout << operations << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve_fast();
    }
    return 0;
}