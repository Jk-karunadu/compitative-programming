#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;

while(t--){
     int n;
        cin>>n;
        int mx = INT_MIN;
        for(int i = 0;i<n;i++){
            int x;
            cin>>x;
            mx = max(mx,x);

        }
        cout<<mx*n<<"\n";
}
return 0;
       
       

    
}