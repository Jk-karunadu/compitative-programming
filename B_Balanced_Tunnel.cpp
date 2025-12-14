#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> entry(n);
    for (int i = 0; i < n; i++) {
        cin >> entry[i];
    }

    vector<int> exit(n);
    for (int i = 0; i < n; i++) {
        cin >> exit[i];
    }
    vector<bool> is_exited(n + 1, false);

    int entry_ptr = 0;
    int fines = 0;
    for (int i = 0; i < n; i++) {
        int car_exiting = exit[i];
        while (is_exited[entry[entry_ptr]]) {
            entry_ptr++;
        }

        if (car_exiting == entry[entry_ptr]) {
            entry_ptr++;
        } else {
            fines++;
        }
        is_exited[car_exiting] = true;
    }

    cout << fines << endl;

    return 0;
}