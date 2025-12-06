#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        
        vector<int> k(n);
        for (int i = 0; i < n; i++) {
            cin >> k[i];
        }
        sort(k.rbegin(), k.rend());
        
        vector<int> c(m);
        for (int i = 0; i < m; i++) {
            cin >> c[i];
        }
        
        long long total_cost = 0;
        int j = 0;
        
        for (int i = 0; i < n; i++) {
            if (j < m && j < k[i]) {
                total_cost += c[j];
                j++;
            } else {
                total_cost += c[k[i] - 1];
            }
        }
        
        cout << total_cost << endl;
    }
    return 0;
}