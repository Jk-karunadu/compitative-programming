// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     int t;
//     cin>>t;

//     while(t--){
//         int s,k,m;
//         cin>>s>>k>>m;
//         int tracker = 0;
//         int sign = -1;
//         int sval = s;
//         while(tracker < m){
//             if(tracker + k > m){
//                 int val = m - tracker;
//                 sval = sval + sign * val;
//                 if(sval < 0){
//                     sval = 0;
//                 }
//                 cout<<sval<<endl;
//                 break;
//             }
//             else{
//                 tracker = tracker + k;
//                 if(k >= s){
//                     sval = sval +sign*s;

//                 }else{
//                     sval = sval + sign * k;
//                 }
//             }
//             sign = sign * -1;
//         }

//         return 0;
//     }

// }

#include <iostream>
#include <algorithm>

using namespace std;



void solve() {
    long long s, k, m;
    if (!(cin >> s >> k >> m)) return;

    if (m < k) {
        cout << max(0LL, s - m) << endl;
    } else {
        long long sand_at_last_flip = min(s, k);
        long long time_since_flip = m % k;
        cout << max(0LL, sand_at_last_flip - time_since_flip) << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}