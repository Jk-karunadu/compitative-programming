#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    if (!(cin >> n)) return 0;

    
    vector<int> a;
    a.push_back(1); 

    
    for (int i = 0; i < n; ++i) {
        int carry = 0;
        for (size_t j = 0; j < a.size(); ++j) {
            int t = a[j] * 2 + carry;
            a[j] = t % 10;
            carry = t / 10;
        }
        while (carry) {
            a.push_back(carry % 10);
            carry /= 10;
        }
    }

    
    int idx = 0;
    while (idx < (int)a.size()) {
        if (a[idx] > 0) { a[idx] -= 1; break; }
       
        a[idx] = 9;
        ++idx;
    }
   
    while (a.size() > 1 && a.back() == 0) a.pop_back();

   
    for (int i = (int)a.size() - 1; i >= 0; --i) cout << a[i];
    cout << '\n';
    return 0;
}
