#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 1000005;
bool is_snowflake[MAX_N];

void precompute() {
    for (int i = 0; i < MAX_N; i++) is_snowflake[i] = false;
    for (long long k = 2; k <= 1000; ++k) {
        long long val = 1 + k; 
        long long power_of_k = k * k;
        val += power_of_k;
        
        while (val < MAX_N) {
            is_snowflake[val] = true;
            if (val + power_of_k * k >= MAX_N) break;
            
            power_of_k *= k;
            val += power_of_k;
        }
    }
}

void solve() {
    int n;
    cin >> n;
    if (is_snowflake[n]) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    precompute();
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}