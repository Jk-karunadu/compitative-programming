#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int get_gcd(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n);
    int ones = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 1) ones++;
    }

    if (ones > 0) {
        cout << n - ones << endl;
        return 0;
    }

    int min_len = 1e9;
    for (int i = 0; i < n; i++) {
        int current_gcd = a[i];
        for (int j = i + 1; j < n; j++) {
            current_gcd = get_gcd(current_gcd, a[j]);
            if (current_gcd == 1) {
                min_len = min(min_len, j - i);
                break; 
            }
        }
    }

    if (min_len == 1e9) {
        cout << -1 << endl;
    } else {
        cout << min_len + n - 1 << endl;
    }

    return 0;
}