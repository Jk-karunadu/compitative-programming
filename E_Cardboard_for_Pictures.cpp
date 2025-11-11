#include <bits/stdc++.h>
using namespace std;

bool is_possible(long long w, vector<long long> &vec, long long c) {
    long long sum = 0;

    for (int i = 0; i < vec.size(); i++) {
        if (w > LLONG_MAX - vec[i]) {
            return false;
        }
        long long side = vec[i] + w;

        if (side > 0 && side > LLONG_MAX / side) {
            return false;
        }
        long long term = side * side;

        if (term > c - sum) {
            return false;
        }
        
        sum = sum + term;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        long long c;
        cin >> c;

        vector<long long> vec(n);

        for (int i = 0; i < n; i++) {
            cin >> vec[i];
        }

        long long l = 0;
        long long h = 2000000001;
        long long ans = 0;
        
        while (l <= h) {
            long long mid = l + (h - l) / 2;

            if (is_possible(mid, vec, c)) {
                ans = mid;
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }

        cout << ans/2 << "\n";
    }
    return 0;
}