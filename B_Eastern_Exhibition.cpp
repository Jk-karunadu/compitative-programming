#include <bits/stdc++.h>
using namespace std;

#define int long long

int solve(vector<int> &x) {
    int n = x.size();
    sort(x.begin(), x.end()); 
    return x[n / 2] - x[(n - 1) / 2] + 1;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> x(n), y(n);
        for (int i = 0; i < n; i++)
            cin >> x[i] >> y[i]; 

        cout << solve(x) * solve(y) << '\n'; 
    }

    return 0;
}
