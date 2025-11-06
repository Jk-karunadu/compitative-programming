#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        vector<int> far(n, 0);  
        vector<int> back(n, 0); 

        vector<int> seen(26, 0);
        int distinct = 0;

      
        for (int i = 0; i < n; i++) {
            if (seen[s[i] - 'a'] == 0)
                distinct++;
            seen[s[i] - 'a']++;
            far[i] = distinct;
        }

      
        fill(seen.begin(), seen.end(), 0);
        distinct = 0;

       
        for (int i = n - 1; i >= 0; i--) {
            if (seen[s[i] - 'a'] == 0)
                distinct++;
            seen[s[i] - 'a']++;
            back[i] = distinct;
        }

     
        int ans = 0;
        for (int i = 0; i < n - 1; i++) {
            ans = max(ans, far[i] + back[i + 1]);
        }

        cout << ans << endl;
    }

    return 0;
}
