#include <bits/stdc++.h>
using namespace std;

int main() {
  

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        long long total_abs_sum = 0;
        int negative_count = 0;
        int min_abs_val = 101; 
        bool has_zero = false;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int val;
                cin >> val;

                if (val < 0) {
                    negative_count++;
                }
                if (val == 0) {
                    has_zero = true;
                }

                int abs_val = abs(val);
                total_abs_sum += abs_val;
                min_abs_val = min(min_abs_val, abs_val);
            }
        }

       
        if (negative_count % 2 == 0 || has_zero) {
           
            cout << total_abs_sum << "\n";
        } else {
           
            cout << total_abs_sum - 2 * min_abs_val << "\n";
        }
    }

    return 0;
}