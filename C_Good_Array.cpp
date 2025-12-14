#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>

using namespace std;
struct Element {
    int value;
    int index;
};

void solve() {
    int n;
    cin >> n;
    vector<Element> elements(n);
    long long total_sum = 0;
    
    for (int i = 0; i < n; ++i) {
        cin >> elements[i].value;
        elements[i].index = i + 1;
        total_sum += elements[i].value;
    }

    sort(elements.begin(), elements.end(), [](const Element& a, const Element& b) {
        return a.value > b.value;
    });
    vector<int> nice_indices;
    for (int j = 0; j < n; ++j) {
        long long removed_val = elements[j].value;
        int removed_index = elements[j].index;
        long long remaining_sum = total_sum - removed_val;
        int pivot_candidate_index;
        
        if (j == 0) {
            pivot_candidate_index = 1;
        } else {
            pivot_candidate_index = 0;
        }
        
        long long pivot_val = elements[pivot_candidate_index].value;
        
        if (2 * pivot_val == remaining_sum) {
            nice_indices.push_back(removed_index);
        }
    }

    cout << nice_indices.size() << "\n";
    if (!nice_indices.empty()) {
        for (size_t i = 0; i < nice_indices.size(); ++i) {
            cout << nice_indices[i] << (i == nice_indices.size() - 1 ? "" : " ");
        }
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}