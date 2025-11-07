#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        string s;
        cin >> n >> k >> s; 

        int count = 0;

      
        for (int i = 0; i < k; i++) {
            if (s[i] == 'W')
                count++;
        }

        int ans = count;

       
        for (int i = k; i < n; i++) {
            if (s[i - k] == 'W') count--; 
            if (s[i] == 'W') count++;    
            ans = min(ans, count);
        }

        cout << ans << "\n";
    }

    return 0;
}
