#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--){
        long long a,b,n;
        cin>>a>>b>>n;

        if(n > (a/b)){
            if((a/b == 1) && (a%b == 0) ){
                cout<<1<<endl;
            }else{
                cout<<2<<endl;
            }
        }
        else{
            cout<<1<<endl;
        }
    }
 
    return 0;
}
