#include <iostream>
#include <vector>
#include <stack>

using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test_cases;
    if (!(cin >> test_cases)) return 0;

    while (test_cases--) {
        int n;
        cin >> n;

        vector<long long> elements(n);
        for (int i = 0; i < n; ++i) {
            cin >> elements[i];
        }

        stack<long long> active_seq;
        int input_length = 0;

        for (const auto& val : elements) {
            if (active_seq.empty()) {
                input_length++;
                active_seq.push(val);
            } 
            else if (val == active_seq.top() + 1) {
                active_seq.push(val);
            } 
            else {
                while (!active_seq.empty() && active_seq.top() >= val) {
                    active_seq.pop();
                }

                if (!active_seq.empty() && val == active_seq.top() + 1) {
                    active_seq.push(val);
                } else {
                    input_length++;
                    while(!active_seq.empty()) active_seq.pop();
                    active_seq.push(val);
                }
            }
        }

        cout << input_length << "\n";
    }

    return 0;
}