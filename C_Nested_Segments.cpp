#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Segment {
    int l, r, id;
};

bool compareSegments(const Segment &a, const Segment &b) {
    if (a.l != b.l) {
        return a.l < b.l; 
    }
    return a.r > b.r; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<Segment> segs(n);
    for (int i = 0; i < n; i++) {
        cin >> segs[i].l >> segs[i].r;
        segs[i].id = i + 1; 
    }

    sort(segs.begin(), segs.end(), compareSegments);

    int max_r = -1;
    int max_r_id = -1;

    for (int i = 0; i < n; i++) {
        if (segs[i].r <= max_r) {
            cout << segs[i].id << " " << max_r_id << endl;
            return 0;
        }

        if (segs[i].r > max_r) {
            max_r = segs[i].r;
            max_r_id = segs[i].id;
        }
    }

    cout << "-1 -1" << endl;

    return 0;
}