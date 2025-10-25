#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    while(n--){
        int t ;
        cin >> t;
        if((t-1)%3 == 0 || (t + 1) % 3 == 0){
            cout << "First" << endl;
        }
        else{
            cout << "Second" << endl;
        }   
    }
}