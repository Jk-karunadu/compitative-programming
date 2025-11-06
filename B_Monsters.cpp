#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long n, k;
        cin >> n >> k;

        vector<pair<long long, long long>> vec;

        for (int i = 0; i < n; i++) {
            long long x;
            cin >> x;
            long long rem = x % k;
            if (rem == 0) rem = k; 
            vec.push_back({rem, i});
        }

       
        sort(vec.begin(), vec.end(), [&](pair<long long, long long> a, pair<long long, long long> b) {
            if (a.first == b.first) return a.second < b.second;
            return a.first > b.first;
        });

        for (int i = 0; i < n; i++) {
            cout << vec[i].second + 1 << " ";
        }
        cout << "\n";
    }

    return 0;
}
