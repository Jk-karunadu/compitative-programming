#include <bits/stdc++.h>
using namespace std;

int main() {
  

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> first, second;

        int cnt = n; 

        while (n--) {
            int m;
            cin >> m;

            vector<long long> arr(m);
            for (int i = 0; i < m; i++) cin >> arr[i];

            sort(arr.begin(), arr.end()); 
            first.push_back(arr[0]);
            second.push_back(arr[1]);
        }

       
        long long min_idx = 0;
        long long minSecond = LLONG_MAX;
        for (int i = 0; i < cnt; i++) {
            if (second[i] < minSecond) {
                minSecond = second[i];
                min_idx = i;
            }
        }

       
        long long sum = 0;
        long long minFirst = LLONG_MAX;

        for (int i = 0; i < cnt; i++) {
            sum += second[i];
            minFirst = min(minFirst, first[i]);
        }

       
        sum = sum - second[min_idx] + minFirst;

        cout << sum << "\n";
    }

    return 0;
}
