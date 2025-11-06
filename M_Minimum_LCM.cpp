#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

long long lcm(long long a, long long b) {
    return (a * b) / gcd(a, b);
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long n;
        cin >> n;

        long long minLCM = LLONG_MAX;
        long long bestA = -1, bestB = -1;

        for (long long i = 1; i * i <= n; i++) {
            if (n % i == 0) {
               
                long long a = i;
                long long b = n - i;
                if (a > 0 && b > 0) {
                    long long currLCM = lcm(a, b);
                    if (currLCM < minLCM) {
                        minLCM = currLCM;
                        bestA = a;
                        bestB = b;
                    }
                }

                long long j = n / i;
                long long c = j;
                long long d = n - j;
                if (c > 0 && d > 0) {
                    long long currLCM = lcm(c, d);
                    if (currLCM < minLCM) {
                        minLCM = currLCM;
                        bestA = c;
                        bestB = d;
                    }
                }
            }
        }

        cout << bestA << " " << bestB << endl;
    }

    return 0;
}
