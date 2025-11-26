#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    
    vector<int> b(n);
    for (int i = 0; i < n; ++i) cin >> b[i];
    vector<int> diff(n);
    int max_val = -2e9 - 7; 
    for (int i = 0; i < n; ++i) {
        diff[i] = a[i] - b[i];
        if (diff[i] > max_val) {
            max_val = diff[i];
        }
    }
    vector<int> strong_vertices;
    for (int i = 0; i < n; ++i) {
        if (diff[i] == max_val) {
            strong_vertices.push_back(i + 1);
        }
    }
    
    cout << strong_vertices.size() << "\n";
    for (int i = 0; i < strong_vertices.size(); ++i) {
        cout << strong_vertices[i] << (i == strong_vertices.size() - 1 ? "" : " ");
    }
    cout << "\n";
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