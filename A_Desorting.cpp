#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        bool not_sorted = false;
        int mn = INT_MAX;

        for (int i = 1; i < n; i++) {
            if (arr[i] < arr[i - 1]) {
                not_sorted = true;
                break;
            }
            mn = min(mn, arr[i] - arr[i - 1]);
        }

        if (not_sorted) {
            cout << 0 << endl;
        } else {
            cout << (mn / 2) + 1 << endl;
        }
    }
    return 0;
}
