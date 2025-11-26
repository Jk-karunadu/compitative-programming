#include <iostream>
#include <vector>
#include <string>

using namespace std;

long long MOD = 998244353;
long long factorial(int n) {
    long long res = 1;
    for (int i = 2; i <= n; i++)
        res = (res * i) % MOD;
    return res;
}

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    
    long long ways = 1; 
    int min_ops = 0;   
    
    int current_len = 1;
    for (int i = 1; i < n; ++i) {
        if (s[i] == s[i-1]) {
            current_len++;
        } else {
            min_ops += (current_len - 1);
            ways = (ways * current_len) % MOD;
            current_len = 1;
        }
    }
    
    min_ops += (current_len - 1);
    ways = (ways * current_len) % MOD;
    ways = (ways * factorial(min_ops)) % MOD;
    
    cout << min_ops << " " << ways << "\n";
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