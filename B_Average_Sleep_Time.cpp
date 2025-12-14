#include <iostream>
#include <vector>
#include <numeric>
#include <iomanip>

using namespace std;

void solve() {
    int n, k;
    if (!(cin >> n >> k)) return;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    long long current_window_sum = 0;
    long long total_sum_of_all_weeks = 0;
    
    int num_weeks = n - k + 1;

    for (int i = 0; i < k; ++i) {
        current_window_sum += a[i];
    }
    total_sum_of_all_weeks += current_window_sum;
    for (int i = k; i < n; ++i) {
        current_window_sum = current_window_sum - a[i - k] + a[i];
        total_sum_of_all_weeks += current_window_sum;
    }
    double overall_average = (double)total_sum_of_all_weeks / num_weeks;
    cout << fixed << setprecision(12) << overall_average << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}