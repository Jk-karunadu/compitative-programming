#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Fast I/O
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int test_cases;
    if (!(cin >> test_cases)) return 0;

    while (test_cases--) {
        int sz;
        cin >> sz;
        
        vector<int> vals(sz + 1);
        for (int i = 1; i <= sz; i++) cin >> vals[i];

        vector<int> L(sz + 1, 0), R(sz + 1, 0), P(sz + 1, 0);
        vector<int> monotonic_stack;

        for (int i = 1; i <= sz; i++) {
            int prev_node = 0;
            while (!monotonic_stack.empty() && vals[monotonic_stack.back()] < vals[i]) {
                prev_node = monotonic_stack.back();
                monotonic_stack.pop_back();
            }

            if (!monotonic_stack.empty()) {
                R[monotonic_stack.back()] = i;
                P[i] = monotonic_stack.back();
            }

            if (prev_node != 0) {
                L[i] = prev_node;
                P[prev_node] = i;
            }

            monotonic_stack.push_back(i);
        }

        int start = 1;
        while (P[start] != 0) start = P[start];

        int max_depth = 0;
        vector<pair<int, int> > stack_dfs;
        stack_dfs.push_back(make_pair(start, 1));

        while (!stack_dfs.empty()) {
            pair<int, int> curr = stack_dfs.back();
            stack_dfs.pop_back();

            int node = curr.first;
            int dist = curr.second;

            if (dist > max_depth) max_depth = dist;

            if (L[node] != 0) stack_dfs.push_back(make_pair(L[node], dist + 1));
            if (R[node] != 0) stack_dfs.push_back(make_pair(R[node], dist + 1));
        }

        cout << sz - max_depth << "\n";
    }

    return 0;
}