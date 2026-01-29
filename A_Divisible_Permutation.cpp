#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<int> p(n);
    int left = 1, right = n;
    
    p[n-1] = 1; 
    bool turn = true; 
    
    int low = 1, high = n;
    for (int i = n - 1; i >= 0; i--) {
        if ((n - 1 - i) % 2 == 0) {
            p[i] = low++;
        } else {
            p[i] = high--;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << p[i] << (i == n - 1 ? "" : " ");
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}