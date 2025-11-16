#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int m = n * (n - 1) / 2;
        vector<long long> vec(m);

        for (int i = 0; i < m; i++) {
            cin >> vec[i];
        }

        sort(vec.begin(), vec.end());

        vector<long long> ans;
        int idx = 0;

        for (int k = n - 1; k >= 1; k--) {
            ans.push_back(vec[idx + k - 1]);
            idx += k;
        }

        
        ans.push_back(vec.back());

        for (long long x : ans) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
