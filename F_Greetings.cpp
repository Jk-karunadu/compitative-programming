#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define Oset tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
// order_of_key(k) : no. of elements < k
// *find_by_order(i) : value at index i (0-based)

using namespace std;

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        // input
        int n;
        cin >> n;
        vector<pair<int, int>> vec(n);
        for (int i = 0; i < n; i++) 
            cin >> vec[i].first >> vec[i].second;

        sort(vec.begin(), vec.end()); 
        Oset st;
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            ans += i - st.order_of_key(vec[i].second); 
            st.insert(vec[i].second); 
        } 
        cout << ans << '\n';
    }

    return 0;
}

