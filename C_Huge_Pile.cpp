#include <bits/stdc++.h>
using namespace std;

map<long long, int> memo;

int solve(long long n, long long k) {
    if (n == k) return 0;
    if (n < k) return -1;
    if (memo.count(n)) return memo[n];

    long long n1 = n / 2;
    long long n2 = n - n1;

    int res1 = solve(n1, k);
    int res2 = solve(n2, k);

    int final_res = -1;
    if (res1 != -1 && res2 != -1) final_res = 1 + min(res1, res2);
    else if (res1 != -1) final_res = 1 + res1;
    else if (res2 != -1) final_res = 1 + res2;

    return memo[n] = final_res; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;
        memo.clear(); 
        cout << solve(n, k) << endl;
    }
    return 0;
}