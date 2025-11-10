#include <bits/stdc++.h>
using namespace std;

void find_all_strings(string s, unordered_set<string>& visited_strings) {
    if (visited_strings.count(s)) {
        return;
    }

    visited_strings.insert(s);

    if (s.length() == 1) {
        return;
    }

    find_all_strings(s.substr(1), visited_strings);
    
    find_all_strings(s.substr(0, 1) + s.substr(2), visited_strings);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        
        unordered_set<string> visited_strings;

        find_all_strings(s, visited_strings);

        cout << visited_strings.size() << endl;
    }
    return 0;
}