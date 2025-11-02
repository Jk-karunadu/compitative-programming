#include <bits/stdc++.h>
using namespace std;

vector<pair<long long, long long>> get_moves(long long x, long long y, long long a, long long b) {
    vector<pair<long long, long long>> moves = {
        {x + a, y + b}, {x + a, y - b}, {x - a, y + b}, {x - a, y - b},
        {x + b, y + a}, {x + b, y - a}, {x - b, y + a}, {x - b, y - a}
    };
    return moves;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long a, b;
        cin >> a >> b;

        long long xK, yK, xQ, yQ;
        cin >> xK >> yK;
        cin >> xQ >> yQ;

        auto king_moves = get_moves(xK, yK, a, b);
        auto queen_moves = get_moves(xQ, yQ, a, b);

        set<pair<long long, long long>> king_set(king_moves.begin(), king_moves.end());
        set<pair<long long, long long>> queen_set(queen_moves.begin(), queen_moves.end());

        int count = 0;
        for (auto &p : king_set) {
            if (queen_set.count(p)) count++;
        }

        cout << count << "\n";
    }

    return 0;
}
