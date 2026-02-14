#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    if (!(cin >> n >> m >> k)) return 0;

    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    int total_length = n;

    vector<int> gaps;
    for (int i = 0; i < n - 1; i++) {
        gaps.push_back(b[i+1] - b[i] - 1);
    }

    sort(gaps.begin(), gaps.end());

    for (int i = 0; i < n - k; i++) {
        total_length += gaps[i];
    }

    cout << total_length << endl;

    return 0;
}