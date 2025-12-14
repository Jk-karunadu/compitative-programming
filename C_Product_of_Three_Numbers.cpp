#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
#include <algorithm>

using namespace std;

void solve() {
    long long n;
    cin >> n;

    long long a = -1, b = -1, c = -1;
    long long temp_n = n;
    for (long long i = 2; i * i <= temp_n; ++i) {
        if (temp_n % i == 0) {
            a = i;
            temp_n /= a;
            break;
        }
    }
    if (a == -1) {
        cout << "NO" << "\n";
        return;
    }
    long long temp_n1 = temp_n;
    for (long long i = a + 1; i * i <= temp_n1; ++i) {
        if (temp_n1 % i == 0) {
            b = i;
            temp_n1 /= b;
            break;
        }
    }
    if (b == -1) {
        temp_n1 = temp_n; 
        for (long long i = 2; i * i <= temp_n1; ++i) {
            if (temp_n1 % i == 0 && i != a) {
                b = i;
                temp_n1 /= b;
                break;
            }
        }
        
        if (b == -1 && temp_n1 != 1 && temp_n1 != a) {
             b = temp_n1;
             temp_n1 = 1;
        }
    }

    c = temp_n1;
    if (a >= 2 && b >= 2 && c >= 2 && a != b && b != c && a != c) {
        cout << "YES" << "\n";
        cout << a << " " << b << " " << c << "\n";
    } else {
        cout << "NO" << "\n";
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