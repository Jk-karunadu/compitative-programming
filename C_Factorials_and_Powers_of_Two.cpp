#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

vector<ll> facts;

int countSetBits(ll n) {
    int count = 0;
    while (n > 0) {
        n &= (n - 1); 
        count++;
    }
    return count;
}

void precompute() {
    ll f = 1;
    for (ll i = 1; i <= 15; ++i) {
        f *= i;
        if (f > 2) facts.push_back(f);
    }
}

int solve(int idx, ll current_n) {
    if (idx == facts.size()) {
        return countSetBits(current_n);
    }

    int res = solve(idx + 1, current_n);

    if (facts[idx] <= current_n) {
        res = min(res, 1 + solve(idx + 1, current_n - facts[idx]));
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    precompute();

    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        cout << solve(0, n) << "\n";
    }

    return 0;
}