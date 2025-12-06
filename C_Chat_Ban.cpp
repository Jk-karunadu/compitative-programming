#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
long long calculate_sum(long long m, long long k) {
    long long total_emotes;
    if (m <= k) {
        total_emotes = m * (m + 1) / 2;
    } else {
        long long full_sum = k * k; 
        long long skipped_messages = 2 * k - 1 - m; 
        long long skipped_sum = skipped_messages * (skipped_messages + 1) / 2;
        total_emotes = full_sum - skipped_sum;
    }
    return total_emotes;
}

void solve() {
    long long k;
    long long x; 
    cin >> k >> x;

    long long total_messages = 2 * k - 1;
    long long max_emotes = k * k;
    if (max_emotes < x) {
        cout << total_messages << "\n";
        return;
    }
    long long low = 1;
    long long high = total_messages;
    long long result = total_messages;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        
        if (calculate_sum(mid, k) >= x) {
            result = mid;
            high = mid - 1; 
        } else {
           
            low = mid + 1; 
        }
    }

    cout << result << "\n";
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