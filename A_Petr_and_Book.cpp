#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> pages(7);
    for (int i = 0; i < 7; i++) {
        cin >> pages[i];
    }

    int j = 0;
    while (n > 0) {
        if (j == 7) j = 0; 
        n -= pages[j];
        j++;
    }

    cout << (j == 0 ? 7 : j) << endl;

    return 0;
}
