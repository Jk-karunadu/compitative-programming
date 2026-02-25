#include <bits/stdc++.h>
using namespace std;

using int64 = long long;

static bool ok(long long s, long long m, long long n) {
    long long l = 0, r = 0;

    for (int i = 0; i <= 120; i++) {
        int sb = (i < 63) ? ((s >> i) & 1LL) : 0;
        bool al = (i < 63) ? (((m >> i) & 1LL) != 0) : false;

        if (al) {
            long long mn = l;
            long long mx = r + n;

            if ((mn & 1LL) != sb) mn++;
            if ((mx & 1LL) != sb) mx--;

            if (mn > mx) return false;

            l = mn >> 1;
            r = mx >> 1;
        } else {
            long long mn = l;
            long long mx = r;

            if ((mn & 1LL) != sb) mn++;
            if ((mx & 1LL) != sb) mx--;

            if (mn > mx) return false;

            l = mn >> 1;
            r = mx >> 1;
        }
    }

    return l == 0 && r == 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        long long s, m;
        cin >> s >> m;

        long long lo = 1, hi = s, ans = -1;

        if (!ok(s, m, hi)) {
            cout << -1 << "\n";
            continue;
        }

        while (lo <= hi) {
            long long mid = (lo + hi) >> 1;
            if (ok(s, m, mid)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}