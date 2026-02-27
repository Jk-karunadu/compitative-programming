#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int max_dishes = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] > max_dishes) {
            max_dishes = a[i];
        }
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == max_dishes) {
            count++;
        }
    }

    cout << count << endl;
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