#include <bits/stdc++.h>
using namespace std;

int main() {
  

    int t;
    cin >> t;

    while (t--) {
        int n, r, b;
        cin >> n >> r >> b;

        string ans = "";

       
        while (r > 0 && b > 0) {
            int mx = ceil(1.0 * r / (b + 1)); 
            ans.append(mx, 'R');
            ans.push_back('B'); 
            r -= mx;
            b -= 1;
        }

       
        if (r > 0) ans.append(r, 'R');

       
        if (b > 0) ans.append(b, 'B');

        cout << ans << "\n";
    }

    return 0;
}
