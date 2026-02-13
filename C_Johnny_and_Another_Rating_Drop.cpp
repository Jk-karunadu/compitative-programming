#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        long long n;
        cin>>n;

        int count = 0;
        for(int i = 1;i<=64;i++){
            if((1LL<<i)&n){
                count++;
            }
        }
        cout<<2*n-count<<endl;
    }

}