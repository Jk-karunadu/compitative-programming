#include<iostream>
#include<climits>
using namespace std;

int main(){
    int n;
    cin >> n;
    int ans = INT_MAX;

  for(int i = 0;i<n;i++){

        int x;
        cin >> x;
        if(x == 0){
            cout << 0 << endl;
            return 0;
        }
        if(abs(x) < ans){
            ans = abs(x);
        }
  }
  cout << (ans) << endl;
    return 0;
}