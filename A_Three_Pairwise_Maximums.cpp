#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int a[3];
        for(int i = 0; i < 3; i++){
            cin >> a[i];
        }
        sort(a, a + 3);

        int x = a[2], y = a[1], z = a[0];

        if(x == y){
            cout << "YES" << endl;
           
            cout << x << " " << z << " " << 1 << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    return 0;
}