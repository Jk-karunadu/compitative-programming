#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    // We use a set to keep track of unique students who receive the ball.
    unordered_set<int> visited;
    
    // The first student receives the ball initially.
    int current_student = 1; 
    visited.insert(current_student);

    // The process occurs exactly n times.
    for (int i = 0; i < n; i++) {
        // String is 0-indexed, so student 'current_student' 
        // corresponds to s[current_student - 1]
        char direction = s[current_student - 1];

        if (direction == 'R') {
            current_student++;
        } else {
            current_student--;
        }
        
        visited.insert(current_student);
    }

    cout << visited.size() << endl;
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