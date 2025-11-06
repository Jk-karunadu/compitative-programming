#include <bits/stdc++.h>
using namespace std;

int main() {
   

    int t;
    cin >> t;

    while (t--) {
        int n, p;
        cin >> n >> p;

        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        vector<pair<int, int>> vec;
        for (int i = 0; i < n; i++) {
            vec.push_back({b[i], a[i]}); 
        }

        sort(vec.begin(), vec.end());

        long long sum = p; 
        long long served = 1; 

        for (int i = 0; i < n && served < n; i++) {
            long long take = min((long long)vec[i].second, (long long)(n - served));
            sum += take * vec[i].first;
            served += take;
        }

        cout << sum << "\n";
    }

    return 0;
}
