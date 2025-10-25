#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin>>n;

    while(n--){
        int m;
        cin>>m;

        int sum = 0;
        for(int i=0;i<m;i++){
            int x;
            cin>>x;
            sum += x;
        }
        if(sum % 2 == 0){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }


    }
}