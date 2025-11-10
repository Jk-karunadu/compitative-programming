#include <iostream> 
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
   
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
   
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (auto& a : arr) {
            cin >> a;
        }
        
        sort(arr.begin(), arr.end());
        
        bool can = true;
       
        for (int j = 1; j < n - 1; j += 2) {
          
            if (arr[j] != arr[j + 1]) {
                can = false;
                break; 
            }
        }
        
        cout << (can ? "YES" : "NO") << '\n';
    }
    return 0;
}