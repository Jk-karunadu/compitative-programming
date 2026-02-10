#include<bits/stdc++.h>
using namespace std;

// The check function calculates the bitwise AND of the range [l, m]
// and checks if that value is >= k
bool check(vector<vector<int>> &pref, int l, int m, int k){
    int current_and = 0;
    int range_len = m - l + 1;
    
    for(int j = 0; j < 31; j++){
        // If the count of set bits in this range equals the range length,
        // it means every number in the range [l, m] has the j-th bit set.
        int count_set_bits = pref[m][j] - pref[l-1][j];
        if(count_set_bits == range_len){
            current_and |= (1 << j);
        }
    }
    return current_and >= k;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];

        // Standard 2D Prefix Sum for bits
        vector<vector<int>> pref(n + 1, vector<int>(31, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 31; j++) {
                pref[i + 1][j] = pref[i][j];
                if (a[i] & (1 << j))
                    pref[i + 1][j]++;
            }
        }

        int q;
        cin >> q;
        while(q--){
            int l_idx, k;
            cin >> l_idx >> k;

            // If the single element at L is already < k, no range starting at L works
            if(a[l_idx - 1] < k){
                cout << -1 << " ";
                continue;
            }

            int low = l_idx, high = n;
            int ans = l_idx;

            // Binary Search for the largest R such that AND(L, R) >= K
            while(low <= high){
                int mid = low + (high - low) / 2;
                
                if(check(pref, l_idx, mid, k)){
                    ans = mid;    // This R works, try to find a larger one
                    low = mid + 1;
                } else {
                    high = mid - 1; // Range AND is too small, shrink R
                }
            }
            cout << ans << " ";
        }
        cout << "\n";
    }
    return 0;
}