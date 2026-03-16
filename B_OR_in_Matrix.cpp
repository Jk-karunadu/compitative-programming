#include <iostream>
#include <vector>

using namespace std;

int main() {
    int m, n;
    if (!(cin >> m >> n)) return 0;

    vector<vector<int>> B(m, vector<int>(n));
    // Initialize A with 1s
    vector<vector<int>> A(m, vector<int>(n, 1));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> B[i][j];
            // If B[i][j] is 0, then the entire row i and column j in A must be 0
            if (B[i][j] == 0) {
                for (int k = 0; k < n; k++) A[i][k] = 0;
                for (int k = 0; k < m; k++) A[k][j] = 0;
            }
        }
    }

    // Verification step: Reconstruct B from our generated A
    bool possible = true;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int current_B_val = 0;
            // Check OR of row i and column j in A
            for (int k = 0; k < n; k++) current_B_val |= A[i][k];
            for (int k = 0; k < m; k++) current_B_val |= A[k][j];

            if (current_B_val != B[i][j]) {
                possible = false;
                break;
            }
        }
        if (!possible) break;
    }

    if (possible) {
        cout << "YES" << endl;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << A[i][j] << (j == n - 1 ? "" : " ");
            }
            cout << endl;
        }
    } else {
        cout << "NO" << endl;
    }

    return 0;
}