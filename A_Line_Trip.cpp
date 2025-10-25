#include<iostream>
#include<climits>
#include<vector>
using namespace std;
int main(){
    int t;
    cin>>t;

    while(t--){
        int n , x;
        cin>>n>>x;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }

        int ans = INT_MIN;
        for(int i = 1;i<n;i++){
            ans = max(ans , a[i]-a[i-1]);
        }
        ans  = max(ans , 2*(x - a[n-1]));
        ans  = max(ans , a[0]);
        cout<<ans<<endl;

    }
    return 0;
}

