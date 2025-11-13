#include <bits/stdc++.h>
using namespace std;

int main() {
    // Added fast I/O for performance
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<long long> vec(n); // Use long long for array elements

        for (int i = 0; i < n; i++) {
            cin >> vec[i];
        }

        // Use long long for sum to prevent overflow
        long long sum = 1;

        sort(vec.begin(), vec.end());
        bool possible = true;
        if(vec[0] != 1){
            cout<<"NO"<<endl;
            continue;
        }

        for (int i = 1; i < n; i++) {
           
            if (vec[i] <= sum) {
                sum = sum + vec[i];
            } else {
                possible = false;
                break;
            }
        }

        if (possible) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    return 0;
}