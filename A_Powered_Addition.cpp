#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        
        long long maxtill = -2e9; 
        long long max_gap = 0;

        for(int i = 0; i < n; i++){
            long long x;
            cin >> x;

            if(x > maxtill){
                maxtill = x;
            } else {
                max_gap = max(max_gap, maxtill - x);
            }
        }

        if(max_gap == 0){
            cout << 0 << "\n";
        } else {
            int T = 0;
            while((1LL << T) - 1 < max_gap){
                T++;
            }
            cout << T << "\n";
        }
    }
    return 0;
}