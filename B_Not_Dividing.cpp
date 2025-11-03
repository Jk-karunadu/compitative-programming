#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<long long> a(n);



        for(int i = 0;i<n;i++){
            cin>>a[i];
        }

        if(a[0] == 1  || a[0] == 0){
            a[0] = 2;

        }

        for(int i = 1;i<n;i++){
            if(a[i] == 1  || a[i] == 0){
                a[i] = 2;
    
            }
            if(a[i]%a[i-1] == 0){
                a[i] = a[i]+1;
            }
           
        }

        for(int i = 0;i<n;i++){
            cout<<a[i];
            cout<<" ";
        }
        cout<<endl;
    }
}