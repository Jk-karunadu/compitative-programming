#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    while(n--){
        int a, b;
        cin >> a >> b;

        if(a % b != 0){
            cout<<1<<endl;
            cout<<a<<endl;
        }
        else{
            cout<<2<<endl;
           cout<<(a-b-1)<<" "<<b+1<<endl;
        }
    }
}