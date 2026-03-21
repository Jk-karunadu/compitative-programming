#include <iostream>

using namespace std;

int fetch(int idx1, int idx2) {
    int res;
    cout << "? " << idx1 << " " << idx2 << endl;
    if (!(cin >> res) || res == -1) exit(0);
    return res;
}

void solve_task() {
    int n_val;
    if (!(cin >> n_val)) return;

    if (fetch(1, 2)) {
        cout << "! 1" << endl;
        return;
    }
    if (fetch(2, 3)) {
        cout << "! 2" << endl;
        return;
    }
    if (fetch(3, 1)) {
        cout << "! 3" << endl;
        return;
    }

    int ptr = 4;
    while (ptr < 2 * n_val) {
        if (fetch(ptr, ptr + 1)) {
            cout << "! " << ptr << endl;
            return;
        }
        ptr += 2;
    }

    cout << "! " << 2 * n_val << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int test_cases;
    if (cin >> test_cases) {
        while (test_cases--) {
            solve_task();
        }
    }
    return 0;
}