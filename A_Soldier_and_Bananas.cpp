#include<iostream>
using namespace std;

int main(){
    int k, n, w;
    cin >> k >> n >> w;
    int total_cost = k * (w * (w + 1)) / 2;
    if(total_cost > n){
        cout << total_cost - n << endl;
    } else {
        cout << 0 << endl;
    }
    return 0;
}