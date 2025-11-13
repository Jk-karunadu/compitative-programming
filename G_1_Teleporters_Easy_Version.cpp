#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        long long c;

        cin>>n>>c;

        vector<long long> vec(n);
        for(int i = 0;i<n;i++){
            int x;
            cin>>x;

            vec[i]= x + i+1;
        }
        sort(vec.begin(),vec.end());
        int count = 0;

        for(int i = 0;i<n;i++){
            if((c - vec[i]) < 0){
                break;
            }
            count++;
            c = c-vec[i];

        }

        cout<<count<<endl;
    }


}