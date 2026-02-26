#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

// Function to calculate (base^exp) % MOD
ll power(ll base, ll exp) {
    ll res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

// Modular Inverse using Fermat's Little Theorem
ll modInverse(ll n) {
    return power(n, MOD - 2);
}

// Factorial function
ll fact(int n) {
    ll res = 1;
    for (int i = 2; i <= n; i++) res = (res * i) % MOD;
    return res;
}

// Combination nCr % MOD
ll nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact(n) * modInverse(fact(r)) % MOD * modInverse(fact(n - r)) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> vec(n);
        for (int i = 0; i < n; i++) cin >> vec[i];

        sort(vec.rbegin(), vec.rend());

        if (vec[0] == vec[k - 1]) {
            int total_count = 0;
            for(int x : vec) if(x == vec[0]) total_count++;
            
            cout << nCr(total_count, k) << endl;
        }
        else {
            int val = vec[k - 1];
            int total_count = 0;
            int needed_count = 0;

            for (int i = 0; i < n; i++) {
                if (vec[i] == val) {
                    total_count++;
                    if (i < k) needed_count++;
                }
            }
            cout << nCr(total_count, needed_count) << endl;
        }
    }
    return 0;
}