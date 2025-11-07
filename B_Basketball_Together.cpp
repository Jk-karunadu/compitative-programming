#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long D;
    if (!(cin >> n >> D)) return 0;

    vector<long long> P(n);
    for (int i = 0; i < n; ++i) cin >> P[i];

    sort(P.begin(), P.end());

    int i = 0, j = n - 1;
    int wins = 0;

    while (i <= j) {
        long long leader = P[j];
       
        long long need = D / leader + 1;  

       
        if (i + (need - 1) <= j) {
            ++wins;
           
            --j;
           
            i += (need - 1);
        } else {
            break; 
        }
    }

    cout << wins << '\n';
    return 0;
}
