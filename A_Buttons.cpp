#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;

    while(n--){
        int a, b, c;
        cin>>a>>b>>c;
        if(a > b){
            cout<<"First"<<endl;

        }
        else if(b > a){
            cout<<"Second"<<endl;

        }
        else{
            if( c % 2 != 0 ){
                cout<<"First"<<endl;
            }
            else{
                cout<<"Second"<<endl;
            }
        }
    }
}