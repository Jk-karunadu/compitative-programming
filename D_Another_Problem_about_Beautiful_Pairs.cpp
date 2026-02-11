// #include <iostream>
// #include <vector>

// using namespace std;

// void solve_beautiful_pairs() {
//     int n;
//     cin >> n;

//     vector<long long> arr(n + 1);
//     for (int i = 1; i <= n; ++i) {
//         cin >> arr[i];
//     }

//     long long beautiful_count = 0;

//     for (int i = 1; i <= n; ++i) {
//         if (arr[i] >= 2 * n) continue; 
//         for (long long k = 1; ; ++k) {
//             long long product = arr[i] * k;
//             int j = i + product;

//             if (j > n) break;

//             if (arr[j] == k) {
//                 beautiful_count++;
//             }
//         }
//     }

//     cout << beautiful_count << "\n";
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int t;
//     cin >> t;
//     while (t--) {
//         solve_beautiful_pairs();
//     }
//     return 0;
// }


#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;

void process_heavy(int n, const vector<int>& active_vals, const vector<vector<int>>& positions, 
                   const vector<int>& heavy_set, ll& total_count) {
    vector<char> seen(n + 1);
    for (int hv : heavy_set) {
        fill(seen.begin(), seen.end(), 0);
        for (int p : positions[hv]) seen[p] = 1;

        for (int ov : active_vals) {
            ll dist = 1LL * hv * ov;
            if (dist > n) break;
            for (int r_idx : positions[ov]) {
                int l_idx = (int)(r_idx - dist);
                if (l_idx >= 1 && seen[l_idx]) total_count++;
            }
        }
    }
}

void process_light(int n, const vector<ll>& data, const vector<int>& active_vals, 
                   const vector<vector<int>>& positions, const vector<int>& light_set, ll& total_count) {
    for (int lv : light_set) {
        for (int ov : active_vals) {
            ll dist = 1LL * lv * ov;
            if (dist > n) break;
            int step = (int)dist;
            for (int l_idx : positions[lv]) {
                int r_idx = l_idx + step;
                if (r_idx <= n && data[r_idx] == ov) total_count++;
            }
        }
    }
}

void run_solver() {
    int n;
    cin >> n;
    vector<ll> elements(n + 1);
    vector<vector<int>> mapping(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> elements[i];
        if (elements[i] <= n) mapping[(int)elements[i]].push_back(i);
    }

    vector<int> present_vals;
    for (int v = 1; v <= n; v++) {
        if (!mapping[v].empty()) present_vals.push_back(v);
    }
    sort(present_vals.begin(), present_vals.end());

    int limit = (int)sqrt(n) + 1;
    vector<int> heavy_list, light_list;
    for (int v : present_vals) {
        if ((int)mapping[v].size() > limit) heavy_list.push_back(v);
        else light_list.push_back(v);
    }

    ll result = 0;
    process_heavy(n, present_vals, mapping, heavy_list, result);
    process_light(n, elements, present_vals, mapping, light_list, result);

    cout << result << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int cases;
    cin >> cases;
    while (cases--) {
        run_solver();
    }
    return 0;
}