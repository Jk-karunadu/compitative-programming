#include <bits/stdc++.h>
using namespace std;

int countTrailingZeros(int n) {
    if (n == 0) return 1;
    int count = 0;
    while (n > 0 && n % 10 == 0) {
        count++;
        n /= 10;
    }
    return count;
}

int countDigits(int n) {
    if (n == 0) return 1;
    int count = 0;
    n = abs(n); 
    while (n > 0) {
        n = n / 10;
        count++;
    }
    return count;
}

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;

    vector<int> trailing(n);
    long long total_digits = 0;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        trailing[i] = countTrailingZeros(a);
        total_digits += countDigits(a);
    }

    sort(trailing.rbegin(), trailing.rend());

    long long removed_zeros = 0;
    for (int i = 0; i < n; i += 2) {
        removed_zeros += trailing[i];
    }

    long long remaining_digits = total_digits - removed_zeros;

    if (remaining_digits <= m) {
        cout << "Anna" << endl;
    } else {
        cout << "Sasha" << endl;
    }
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