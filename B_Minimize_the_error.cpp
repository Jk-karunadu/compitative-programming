#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k1, k2;
    if (!(cin >> n >> k1 >> k2)) return 0;

    int k = k1 + k2;
    vector<int> a(n), b(n);

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    priority_queue<int> q;
    for (int i = 0; i < n; i++) {
        q.push(abs(a[i] - b[i]));
    }

    while (k > 0) {
        int val = q.top();
        q.pop();

        val = abs(val - 1);
        
        q.push(val);
        k--;
    }

    long long ans = 0; 
    while (!q.empty()) {
        long long val = q.top();
        q.pop();
        ans += (val * val);
    }

    cout << ans << endl;

    return 0;
}