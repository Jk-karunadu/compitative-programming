#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    for(int i=0;i<n;i++){
        int n,m;
        cin >> n >> m;
        int count = 0;
        for(int j=0;j<n;j++){
            for(int k=0;k<m;k++){
                char c;
                cin >> c;
             if(k==m-1 && c=='R' || j==n-1 && c=='D'){
                count++;
            }
           
        }
    }
    cout<<count<<endl;
}
}