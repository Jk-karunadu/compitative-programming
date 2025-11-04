#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long n, k;
        cin >> n >> k;

        vector<long long> vec(n * k);
        for (int i = 0; i < n * k; i++) {
            cin >> vec[i];
        }

       
        long long top = (n + 1) / 2;

      
        long long skip = n - top;

        long long sum = 0;
        long long index = n * k - 1 - skip;

       
        for (int i = 0; i < k; i++) {
            sum += vec[index];
            index -= (skip + 1);
        }

        cout << sum << endl;
    }
    return 0;
}
