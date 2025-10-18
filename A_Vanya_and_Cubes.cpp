#include<iostream>
using namespace std;

int main(){
    int t;
    cin >> t;

    int count = 0;
   for(int i = 1; i * (i+1)/2 <= t; i++){
count++;
         t -= i*(i+1)/2;

   }
    cout << count << endl;
     return 0;
}