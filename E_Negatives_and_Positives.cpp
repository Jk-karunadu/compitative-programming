#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        vector<long long> vec(n);
        int num_of_neg = 0;
        bool zero_present = false;
        long long sum = 0;
        long long mn = LLONG_MAX;

        for(int i = 0;i<n;i++){
            long long x;
            cin>>x;

            if(x == 0){
                zero_present = true;
            }else if( x < 0){
                num_of_neg++;
            }
            vec[i] = abs(x);
            sum = sum + abs(x);
            mn  = min(mn,abs(x));
        }

        if(zero_present || num_of_neg%2 == 0){
            cout<<sum<<endl;
        }
        else{
            cout<<(sum - 2*mn)<<endl;
        }

        
    }
    

}