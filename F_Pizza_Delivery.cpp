#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

const long long MOD = 1e9 + 7;

void solve() {
    int n;
    long long Ax, Ay, Bx, By;
    cin >> n >> Ax >> Ay >> Bx >> By;

    // Map sorts X-coordinates automatically
    map<long long, pair<long long, long long>> groups;
    vector<long long> x(n), y(n);
    for (int i = 0; i < n; i++) cin >> x[i];
    for (int i = 0; i < n; i++) cin >> y[i];
    
    for (int i = 0; i < n; i++) {
        if (groups.count(x[i])) {
            groups[x[i]].first = min(groups[x[i]].first, y[i]);
            groups[x[i]].second = max(groups[x[i]].second, y[i]);
        } else {
            groups[x[i]] = {y[i], y[i]};
        }
    }

    // dp_low: min vertical distance ending at min_y of current x
    // dp_high: min vertical distance ending at max_y of current x
    long long dp_low = 0, dp_high = 0;
    long long prev_low_y = Ay, prev_high_y = Ay;

    for (auto const& [cur_x, range] : groups) {
        long long cur_min = range.first;
        long long cur_max = range.second;
        long long dist_in_group = cur_max - cur_min;

        // Transition to ending at cur_min
        long long to_min = min(
            dp_low + abs(cur_max - prev_low_y) + dist_in_group,
            dp_high + abs(cur_max - prev_high_y) + dist_in_group
        );

        // Transition to ending at cur_max
        long long to_max = min(
            dp_low + abs(cur_min - prev_low_y) + dist_in_group,
            dp_high + abs(cur_min - prev_high_y) + dist_in_group
        );

        dp_low = to_min;
        dp_high = to_max;
        prev_low_y = cur_min;
        prev_high_y = cur_max;
    }

    // Final stretch to B
    long long min_v_dist = min(dp_low + abs(By - prev_low_y), dp_high + abs(By - prev_high_y));
    
    // Total time = Total X move + Total Y move
    long long total_x = Bx - Ax;
    long long result = (total_x + min_v_dist);
    
    cout << result % MOD << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}