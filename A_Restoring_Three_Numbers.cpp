#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int a[4];
    for (int i = 0; i < 4; i++) {
        if (!(cin >> a[i])) return 0;
    }

    sort(a, a + 4);

    int val1 = a[3] - a[0];
    int val2 = a[3] - a[1];
    int val3 = a[3] - a[2];

    cout << val1 << " " << val2 << " " << val3 << endl;

    return 0;
}