#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        unordered_map<int, int> am, bm;

       
        int prev, count = 1;
        cin >> prev;
        for (int i = 1; i < n; i++) {
            int x;
            cin >> x;
            if (x == prev) {
                count++;
            } else {
                am[prev] = max(am[prev], count);
                prev = x;
                count = 1;
            }
        }
        am[prev] = max(am[prev], count);

       
        cin >> prev;
        count = 1;
        for (int i = 1; i < n; i++) {
            int x;
            cin >> x;
            if (x == prev) {
                count++;
            } else {
                bm[prev] = max(bm[prev], count);
                prev = x;
                count = 1;
            }
        }
        bm[prev] = max(bm[prev], count); 

        
        int ans = 0;

        for (auto &p : am) {
            int key = p.first;
            int aCount = p.second;
            int bCount = bm.count(key) ? bm[key] : 0;
            ans = max(ans, aCount + bCount);
        }

        for (auto &p : bm) {
            int key = p.first;
            int bCount = p.second;
            int aCount = am.count(key) ? am[key] : 0;
            ans = max(ans, aCount + bCount);
        }

        cout << ans << "\n";
    }

    return 0;
}
