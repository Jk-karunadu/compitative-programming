#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin >> n;

    while(n--){
        int t;
        cin>>t;

        vector<int> arr(t);
        for(int i = 0; i < t; i++){
            cin >> arr[i];
        }   

        if(arr[0]  != 1){
            cout<<"NO"<<endl;
           
        }else{
            cout<<"YES"<<endl;
        }

        
    }
}