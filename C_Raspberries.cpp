#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        int diff = INT_MAX;
        int evens = 0;
        int minToDiv4 = INT_MAX;
        bool divisibleBy4 = false;

        if (k != 4) {
            for (int i = 0; i < n; i++) {
                int x;
                cin >> x;

                int rem = x % k;
                if (rem == 0)
                    diff = 0; 
                else
                    diff = min(diff, k - rem);
            }
        } 
        else {
            for (int i = 0; i < n; i++) {
                int x;
                cin >> x;

                if (x % 2 == 0) evens++;
                if (x % 4 == 0) divisibleBy4 = true;

                int rem = x % 4;
                minToDiv4 = min(minToDiv4, (4 - rem) % 4);
            }

            if (evens >= 2 || divisibleBy4)
                diff = 0;
            else if (evens == 1)
                diff = min(1, minToDiv4);
            else
                diff = min(2, minToDiv4);
        }

        cout << diff << "\n";
    }

    return 0;
}
