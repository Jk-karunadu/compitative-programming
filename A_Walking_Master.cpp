#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;

    while(n--){
     int a, b , c, d;
     cin>>a>>b>>c>>d;

     if(d >= b){
        a = a + abs(d - b);
        if(c <= a){
            cout<<abs(c-a)+abs(d-b)<<endl;
        }else{
            cout<<"-1"<<endl;
        }

     }
     else{
        cout<<"-1"<<endl;
     }

    }
}