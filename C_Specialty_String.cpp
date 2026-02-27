#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    stack<char> st;

    for (char c : s) {
        if (!st.empty() && st.top() == c) {
            st.pop();
        } else {
            st.push(c);
        }
    }

    if (st.empty()) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
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