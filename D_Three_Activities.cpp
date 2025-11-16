#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

       
        vector<pair<long long, int>> a(n), b(n), c(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i].first;
            a[i].second = i;
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i].first;
            b[i].second = i;
        }
        for (int i = 0; i < n; i++) {
            cin >> c[i].first;
            c[i].second = i;
        }

       
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        sort(c.begin(), c.end());

        long long max_ans = 0;

        
        for (int i = n - 1; i >= max(0, n - 3); i--) {
            for (int j = n - 1; j >= max(0, n - 3); j--) {
                for (int k = n - 1; k >= max(0, n - 3); k--) {

                  
                    if (a[i].second != b[j].second &&
                        a[i].second != c[k].second &&
                        b[j].second != c[k].second) 
                    {
                        long long sum = a[i].first + b[j].first + c[k].first;
                        max_ans = max(max_ans, sum);
                    }
                }
            }
        }

        cout << max_ans << endl;
    }

    return 0;
}
