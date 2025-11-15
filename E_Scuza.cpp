#include<bits/stdc++.h>
using namespace std;

int binary(vector<long long> &pmax, int n , long long val){

    int l = 0;
    int h = n-1;
    int ans = -1;

    while(l <= h){
        int mid = l+(h-l)/2;

        if(pmax[mid] <= val){
            ans = mid;
            l = mid+1;
        }else{
            h = mid-1;
        }

    }

    return ans;
}

int main(){
    int t;
    cin>>t;

    while(t--){
        int n , q;

        cin>>n>>q;
        vector<long long> a(n);
        vector<long long> b(q);


        for(int i = 0;i<n;i++){
            cin>>a[i];
        }

        for(int i = 0;i<q;i++){
            cin>>b[i];
        }

        vector<long long> pmax(n),psum(n);
        pmax[0] = a[0];
        psum[0] = a[0];

        for(int i = 1;i<n;i++){
            pmax[i] = max(pmax[i-1],a[i]);
            psum[i] = psum[i-1] + a[i];
        }

        for(int i = 0;i<q;i++){
            long long val = b[i];

            int idx = binary(pmax, n , val);

            if(idx == -1){
                cout<<0<<" ";
            }
            else{
                cout<<psum[idx]<<" ";
            }
        }
        cout<<endl;



    }
}