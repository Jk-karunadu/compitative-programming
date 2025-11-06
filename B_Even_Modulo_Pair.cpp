// #include <bits/stdc++.h>
// using namespace std;

// int main() {
   

//     int t;
//     cin >> t;
//     while (t--) {
//         int n;
//         cin >> n;
//         vector<long long> odds, evens;

//         for (int i = 0; i < n; i++) {
//             long long x;
//             cin >> x;
//             if (x % 2 == 0)
//                 evens.push_back(x);
//             else
//                 odds.push_back(x);
//         }

//         bool found = false;
//         long long x = -1, y = -1;

      
//         for (int i = 0; i + 1 < (int)evens.size(); i++) {
//             if ((evens[i + 1] % evens[i]) % 2 == 0) {
//                 x = evens[i];
//                 y = evens[i + 1];
//                 found = true;
//                 break;
//             }
//         }

       
//         if (!found) {
//             for (int i = 0; i + 1 < (int)odds.size(); i++) {
//                 if ((odds[i + 1] % odds[i]) % 2 == 0) {
//                     x = odds[i];
//                     y = odds[i + 1];
//                     found = true;
//                     break;
//                 }
//             }
//         }

//         if (found)
//             cout << x << " " << y << "\n";
//         else
//             cout << "-1\n";
//     }
// }


#include <bits/stdc++.h>
using namespace std;

int main() {
 

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        bool found = false;
        for (int i = n - 1; i > 0 && !found; i--) {
            for (int j = i - 1; j >= 0 && j >= i - 60; j--) {
                if (((a[i] % a[j]) & 1) == 0) {
                    cout << a[j] << " " << a[i] << "\n";
                    found = true;
                    break;
                }
            }
        }

        if (!found) cout << -1 << "\n";
    }
}
