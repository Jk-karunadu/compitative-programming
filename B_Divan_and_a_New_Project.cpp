#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<long long, int>> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i].first;  
            a[i].second = i + 1; 
        }

        
        sort(a.rbegin(), a.rend());

        vector<long long> pos(n + 1);
        long long total = 0;
        int right = 1, left = -1;
        bool goRight = true;

        pos[0] = 0; 

        
        for (int i = 0; i < n; i++) {
            if (goRight) {
                pos[a[i].second] = right;
                total += 2LL * a[i].first * right;
                right++;
            } else {
                pos[a[i].second] = left;
                total += 2LL * a[i].first * (-left);
                left--;
            }
            goRight = !goRight;
        }

        cout << total << "\n";
        for (int i = 0; i <= n; i++) {
            cout << pos[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}
