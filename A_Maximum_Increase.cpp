#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    int final = 0;
    int ans = 0;
  int pre = 0;
    for(int i = 0;i<n;i++){
        int a ;
        cin>>a;
        if(pre < a){
            ans++;
            final = max(final,ans);
            pre = a;
        }
        else{
            ans = 1;
            pre = a;
        }


    }
    cout<<final<<endl;
    return 0;
}