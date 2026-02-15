#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD_VAL = 1e9 + 7;

struct VertexData {
    int left_child, right_child;
    long long subtree_cost;
    long long total_path_sum;
};

VertexData nodes[300005];

void calculate_subtree_weights(int n) {
    vector<int> process_order;
    vector<int> queue = {0}; 
    
    queue = {1};
    int head = 0;
    while(head < queue.size()){
        int curr = queue[head++];
        if(nodes[curr].left_child != 0){
            queue.push_back(nodes[curr].left_child);
            queue.push_back(nodes[curr].right_child);
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        int u = queue[i];
        if (nodes[u].left_child == 0) {
            nodes[u].subtree_cost = 1;
        } else {
            long long left_v = nodes[nodes[u].left_child].subtree_cost;
            long long right_v = nodes[nodes[u].right_child].subtree_cost;
            nodes[u].subtree_cost = (3 + left_v + right_v) % MOD_VAL;
        }
    }

    for (int i = 0; i < n; i++) {
        int u = queue[i];
        long long parent_sum = 0;
    }
}

void propagate_totals(int start_node, long long initial_s) {
    vector<pair<int, long long>> stack;
    stack.push_back({start_node, initial_s});

    while (!stack.empty()) {
        pair<int, long long> curr = stack.back();
        stack.pop_back();

        int u = curr.first;
        long long s_val = curr.second;

        s_val = (s_val + nodes[u].subtree_cost) % MOD_VAL;
        nodes[u].total_path_sum = s_val;

        if (nodes[u].left_child != 0) {
            stack.push_back({nodes[u].right_child, s_val});
            stack.push_back({nodes[u].left_child, s_val});
        }
    }
}

void execute_test_case() {
    int node_count;
    if (!(cin >> node_count)) return;

    for (int i = 1; i <= node_count; i++) {
        cin >> nodes[i].left_child >> nodes[i].right_child;
        nodes[i].subtree_cost = 0;
        nodes[i].total_path_sum = 0;
    }
    auto recursive_f = [&](auto self, int u) -> void {
        if (nodes[u].left_child == 0) {
            nodes[u].subtree_cost = 1;
            return;
        }
        self(self, nodes[u].left_child);
        self(self, nodes[u].right_child);
        nodes[u].subtree_cost = (3 + nodes[nodes[u].left_child].subtree_cost + nodes[nodes[u].right_child].subtree_cost) % MOD_VAL;
    };
    
    recursive_f(recursive_f, 1);
    
    propagate_totals(1, 0);

    for (int i = 1; i <= node_count; i++) {
        cout << nodes[i].total_path_sum << (i == node_count ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test_instances;
    cin >> test_instances;
    while (test_instances--) {
        execute_test_case();
    }
    return 0;
}