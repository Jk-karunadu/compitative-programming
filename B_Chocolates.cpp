#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    long long total = 0;
    long long prev = a[n - 1]; 
    total += prev;

   
    for (int i = n - 2; i >= 0; i--) {
       
        long long curr = min(a[i], prev - 1);
        if (curr < 0) curr = 0; 
        total += curr;
        prev = curr; 
    }

    cout << total << endl;
    return 0;
}
