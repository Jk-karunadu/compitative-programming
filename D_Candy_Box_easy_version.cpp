#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    
    map<int, int> counts;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        counts[a]++;
    }

    vector<int> freq;
    for (auto const& [type, count] : counts) {
        freq.push_back(count);
    }
    sort(freq.rbegin(), freq.rend());

    long long total_candies = 0;
    int last_allowed = freq[0]; 
    
    for (int f : freq) {
        int taken = min(f, last_allowed);
        
        if (taken < 0) taken = 0;
        
        total_candies += taken;
        
        last_allowed = taken - 1;
    }

    cout << total_candies << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> q;
    while (q--) {
        solve();
    }
    return 0;
}