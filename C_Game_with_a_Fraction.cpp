#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long n, m;
        cin >> n >> m;
       

        if (m > n && 2 * m <= 3 * n) {
            cout << "Bob\n";
        } else {
            cout << "Alice\n";
        }
    }
    return 0;
}
