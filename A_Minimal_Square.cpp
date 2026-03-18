#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    // Speed up I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0; 
    
    while (t--) {
        long long a, b;
        cin >> a >> b;

        long long side = max(2 * min(a, b), max(a, b));
        
        cout << (side * side) << "\n";
    }

    return 0;
}