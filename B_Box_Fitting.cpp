#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    int W; 
    cin >> n >> W;

    multiset<int> ms;
    for(int i = 0; i < n; i++){
        int w;
        cin >> w;
        ms.insert(w);
    }

    int height = 1;
    int space_left = W;

    while(!ms.empty()){
        auto it = ms.upper_bound(space_left);

        if(it != ms.begin()){
            it--; 
            
            int val = *it;
            space_left -= val;
            ms.erase(it);
        }
        else {
            height++;
            space_left = W;
        }
    }

    cout << height << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}