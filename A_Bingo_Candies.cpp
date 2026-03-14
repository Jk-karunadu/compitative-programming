#include <iostream>
#include <vector>
#include <map>

using namespace std;

void solve() {
    int n;
    cin >> n;

    map<int, int> counts;
    int total_tiles = n * n;
    
    for (int i = 0; i < total_tiles; ++i) {
        int color;
        cin >> color;
        counts[color]++;
    }
    if (n == 1) {
        cout << "NO" << endl;
        return;
    }
bool possible = true;
    int limit = n * n - n;

    for (auto const& x : counts) {
        int count = x.second;
        if (count > limit) {
            possible = false;
            break;
        }
    }

    if (possible) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}