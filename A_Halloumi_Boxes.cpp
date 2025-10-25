#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> boxes(n);
        for (int i = 0; i < n; i++) {
            cin >> boxes[i];
        }

     if(is_sorted(boxes.begin(), boxes.end())){
       
cout<<"YES"<<endl;
      }
      else if(k == 1){
          cout<<"NO"<<endl;
      }
      else{
          cout<<"YES"<<endl;
      }
    }
    return 0;
}
