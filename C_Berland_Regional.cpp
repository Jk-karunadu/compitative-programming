#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;
    
    vector<int> uni(n);
    for (int i = 0; i < n; i++) cin >> uni[i];

    vector<vector<long long>> school_data(n + 1);
    for (int i = 0; i < n; i++) {
        long long skill;
        cin >> skill;
        school_data[uni[i]].push_back(skill);
    }

    for (int i = 1; i <= n; i++) {
        if (school_data[i].empty()) continue;
        
        sort(school_data[i].begin(), school_data[i].end(), greater<long long>());

        int sz = school_data[i].size();
        for (int j = 1; j < sz; j++) {
            school_data[i][j] += school_data[i][j - 1];
        }
    }

    vector<long long> total_strength(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        int sz = school_data[i].size();
        for (int k = 1; k <= sz; k++) {
            int students_count = (sz / k) * k;
            total_strength[k] += school_data[i][students_count - 1];
        }
    }

    for (int k = 1; k <= n; k++) {
        cout << total_strength[k] << (k == n ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}