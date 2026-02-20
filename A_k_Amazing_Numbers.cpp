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
        unordered_map<int,vector<int>> m;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            m[x].push_back(i);
        }

        vector<int> ans(n + 1, 1e9); 
        for(auto &it : m){
            vector<int>& v = it.second;
            int sz = v.size();
            int prev = -1;
            int mxs = 0;
            
            for(int i=0; i<sz; i++){
               mxs = max(mxs, v[i] - prev);
               prev = v[i];
            }
            mxs = max(mxs, n - prev); 
            
            if (mxs <= n) {
                ans[mxs] = min(ans[mxs], it.first);
            }
        }

        int current_min = 1e9;
        for(int i=1; i<=n; i++){
            current_min = min(current_min, ans[i]);
            if(current_min == 1e9) cout << -1 << " ";
            else cout << current_min << " ";
        }
        cout << endl;
    }
    return 0;
}