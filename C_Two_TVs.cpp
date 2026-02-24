#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<pair<int, int>> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i].first >> vec[i].second;
    }

    sort(vec.begin(), vec.end());

    int tv1_end = -1;
    int tv2_end = -1;

    for (int i = 0; i < n; i++) {
        int start = vec[i].first;
        int end = vec[i].second;

        if (start > tv1_end) {
            tv1_end = end;
        } else if (start > tv2_end) {
            tv2_end = end;
        } else {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
    return 0;
}