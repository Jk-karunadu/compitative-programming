#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<int> p(n + 1);
    
    
    p[n] = 1;
    
    for (int i = 2; i < n; ++i) {
        p[i] = i ^ 1;
    }
    
    if (n % 2 == 0) {
        p[1] = n;
    } else {
        p[1] = n - 1;
    }
    
    for (int i = 1; i <= n; ++i) {
        cout << p[i] << (i == n ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}