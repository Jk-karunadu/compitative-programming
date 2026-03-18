#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;

    if ((n / 2) % 2 != 0) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
    
    long long even_sum = 0;
    long long odd_sum = 0;

    for (int i = 1; i <= n / 2; i++) {
        int val = i * 2;
        cout << val << " ";
        even_sum += val;
    }

    for (int i = 1; i < n / 2; i++) {
        int val = (i * 2) - 1;
        cout << val << " ";
        odd_sum += val;
    }

    cout << even_sum - odd_sum << endl;
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