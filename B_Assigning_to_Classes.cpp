#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;

    for(int i=0;i<n;i++){
        int t;
        cin>>t;

        vector<int> vec(2*t);

        for(int j = 0;j<2*t;j++){
            cin>>vec[j];
        }
        sort(vec.begin(),vec.end());
        cout<<vec[t]-vec[t-1]<<endl;


    }
    return 0;
}