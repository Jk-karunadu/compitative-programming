#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    long long total_good_subarrays = 0;
    
    map<int, int> frequency;

    frequency[0] = 1;

    int current_prefix_sum = 0;
    for (int i = 1; i <= n; i++) {
        current_prefix_sum += (s[i-1] - '0');
        
        int val = current_prefix_sum - i;

        total_good_subarrays += frequency[val];
        
        frequency[val]++;
    }

    cout << total_good_subarrays << endl;
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