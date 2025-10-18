#include <iostream>
using namespace std;

int main() {
    int k;
    cin >> k;

    string s;
    cin >> s;

    int arr[26] = {0};
    for (char c : s) {
        arr[c - 'a']++;
    }

    
    for (int i = 0; i < 26; i++) {
        if (arr[i] % k != 0) {
            cout << -1 << endl;
            return 0;
        }
    }

    string part = "";
    for (int i = 0; i < 26; i++) {
        if (arr[i] > 0) {
            part += string(arr[i] / k, 'a' + i);
        }
    }

   
    string finalResult = "";
    for (int i = 0; i < k; i++) {
        finalResult += part;
    }

    cout << finalResult << endl;
    return 0;
}
