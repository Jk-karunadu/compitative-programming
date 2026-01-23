#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    long long x;
    cin >> n >> x;

    long long sum = 0;       
    long long maxval = -2e18; 

    for(int i = 0; i < n; i++){
        long long a, b, c;
        cin >> a >> b >> c;

        sum += a * (b - 1);

        long long current_gain = (a * b) - c;

        if(current_gain > maxval){
            maxval = current_gain;
        }
    }

    if(sum >= x){
        cout << 0 << endl;
    } 
    else {
        if(maxval <= 0){
            cout << -1 << endl;
        } 
        else {
            long long needed = x - sum;
            long long count = (needed + maxval - 1) / maxval;
            cout << count << endl;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}