#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    bool found_67 = false;
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 67) {
            found_67 = true;
        }
    }

    if (found_67) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
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