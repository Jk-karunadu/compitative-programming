#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }

        int ans = 0;
        ans = ans + (a[0] == 1 ? 1 : 0);

        for(int i = 1;i<n;i++){
            if(a[i] == 0){
                continue;
            }

            int j = i;
            while(j<n && a[j] == 1){
                j++;
            }
            ans = ans + (j-i)/3;
            i = j-1;
        }
        cout<<ans<<endl;
    }
}