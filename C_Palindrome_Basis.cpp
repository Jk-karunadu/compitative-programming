#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int MAXN = 40000;
const int MOD = 1e9 + 7;

int dp[MAXN + 1];
vector<int> palindromes;
bool isPalindrome(int n) {
    string s = to_string(n);
    string r = s;
    reverse(r.begin(), r.end());
    return s == r;
}

void precompute() {
    for (int i = 1; i <= MAXN; ++i) {
        if (isPalindrome(i)) {
            palindromes.push_back(i);
        }
    }

    dp[0] = 1;

    for (int p : palindromes) {
        for (int j = p; j <= MAXN; ++j) {
            dp[j] = (dp[j] + dp[j - p]) % MOD;
        }
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    precompute();

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << dp[n] << "\n";
    }

    return 0;
}