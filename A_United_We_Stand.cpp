#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n ;
        cin>>n;

        long long arr[n];
        long long mx = INT_MIN;

        for(int i = 0;i<n;i++)
        {
            cin>>arr[i];
            mx = max(mx , arr[i]);

        }
        vector<long long> c;
        vector<long long> b;

        for(int i = 0;i<n;i++){
            if(arr[i] != mx){
                b.push_back(arr[i]);
               
            }
            else{
                c.push_back(arr[i]);
            }
        }
        if(b.size() == 0){
            cout<<-1<<endl;
        }
        else{
           cout<<b.size()<<" "<<c.size()<<endl;
              for(int i = 0;i<b.size();i++){
                cout<<b[i]<<" ";
              }
                cout<<endl;
                for(int i = 0;i<c.size();i++){
                cout<<c[i]<<" ";
                }
                cout<<endl;
        }
    }


}