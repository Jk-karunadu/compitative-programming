#include <iostream>
#include <vector>
#include <unordered_map>
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

        unordered_map<int, int> count;
        for (int i = 0; i < n; i++) {
            count[arr[i]]++;
        }

        if (count.size() == 1) {
            cout << "Yes" << endl; // all same
        } 
        else if (count.size() == 2) {
            auto it = count.begin();
            int a = it->second;
            it++;
            int b = it->second;

            // difference in counts should be at most 1
            if (abs(a - b) <= 1)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        } 
        else {
            cout << "No" << endl;
        }
    }

    return 0;
}
