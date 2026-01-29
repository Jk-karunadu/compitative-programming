#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Executes the core logic for each test case.
 * Maintains the exact O(N log(10^9)) complexity.
 */
void process_test_case() {
    int size;
    if (!(cin >> size)) return;

    vector<int> elements(size);
    for (int &val : elements) {
        cin >> val;
    }

    // Step 1: Find global extremes using built-in functions
    int min_val = *min_element(elements.begin(), elements.end());
    int max_val = *max_element(elements.begin(), elements.end());

    // Step 2: Check if already sorted (original 'f' logic)
    if (is_sorted(elements.begin(), elements.end())) {
        cout << "-1\n";
        return;
    }

    // Step 3: Reference sorted version for comparison
    vector<int> sorted_elements = elements;
    sort(sorted_elements.begin(), sorted_elements.end());

    // Step 4: Binary search for the 'k' value
    int low = 1, high = 1000000000;
    int result_k = 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        long long lower_bound_u = (long long)max_val - mid;
        long long upper_bound_v = (long long)min_val + mid;

        bool is_valid = true;

        if (lower_bound_u < upper_bound_v) {
            for (int i = 0; i < size; ++i) {
                // Logic: verify if values within the gap match sorted order
                if (elements[i] > lower_bound_u && elements[i] < upper_bound_v) {
                    if (elements[i] != sorted_elements[i]) {
                        is_valid = false;
                        break;
                    }
                }
            }
        }

        if (is_valid) {
            result_k = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << result_k << "\n";
}

int main() {
    // Fast I/O configuration
    ios::sync_with_stdio(0);
    cin.tie(0);

    int test_count;
    if (cin >> test_count) {
        while (test_count--) {
            process_test_case();
        }
    }
    return 0;
}