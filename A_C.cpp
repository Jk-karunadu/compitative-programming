#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    for(int i= 0;i<n;i++){
        int a,b,c;
        cin >> a >> b >> c;

        int steps = 0;
       while(c >= b && c >= a){
        steps++;

        if(a < b){
            a = a + b;
        }else{
            b = b + a;
        }
       }
         cout << steps << endl;

    }
    return 0;
}