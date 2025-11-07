#include <bits/stdc++.h>
using namespace std;


int highestSetBitPosition(int n) {
    int k = 0;
    while ((1 << (k + 1)) <= n - 1) {
        ++k;
    }
    return k;
}


void printSequence(int n) {
    int k = highestSetBitPosition(n);

    
    for (int i = (1 << k) - 1; i >= 0; --i) {
        cout << i << ' ';
    }

   
    for (int i = (1 << k); i < n; ++i) {
        cout << i << ' ';
    }

    cout << '\n';
}

int main() {

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        printSequence(n);
    }

    return 0;
}
