#include <iostream>
#include <vector>
#include <map>
#include <numeric>

using namespace std;
long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<long long> a(n), b(n);

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    map<pair<long long, long long>, int> counts;
    int always_zero = 0;
    int max_freq = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            if (b[i] == 0) {
                always_zero++; 
            }
        } else {
            long long num = -b[i];
            long long den = a[i];
            
            long long common = gcd(abs(num), abs(den));
            num /= common;
            den /= common;

            if (den < 0) {
                num = -num;
                den = -den;
            }

            counts[{num, den}]++;
            max_freq = max(max_freq, counts[{num, den}]);
        }
    }

    cout << max_freq + always_zero << endl;

    return 0;
}