#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main(){
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i = 0;i<n;i++){
        cin>>arr[i];

    }
    vector<vector<int>> res;

    for(int i = 0;i<n;i++){
        int unit = 1;
        vector<int> ans;
        int n = arr[i];
        while(n>0){
            int rem = n%10;
            if(rem!=0){
                ans.push_back(rem*unit);
            }
            unit*=10;
            n/=10;
        }
      
        res.push_back(ans);
    }
    for(int i = 0;i<res.size();i++){
        cout<<res[i].size()<<endl;
        for(int j = 0;j<res[i].size();j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}