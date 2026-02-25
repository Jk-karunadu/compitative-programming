#include <iostream>
#include <vector>

using namespace std;

long long compute_gcd(long long a, long long b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

long long get_safe_lcm(long long a, long long b, long long limit) {
    if (a == 0 || b == 0) return 0;
    long long common = compute_gcd(a, b);
    
    long long factor = a / common;
    
    if (b > 0 && factor > limit / b) {
        return limit + 1;
    }
    
    long long result = factor * b;
    return (result > limit) ? limit + 1 : result;
}

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;
    
    int max_range = n + m;
    vector<int> a_vals(n), b_vals(m);
    vector<bool> present_in_a(max_range + 1, false);

    for (int i = 0; i < n; i++) {
        cin >> a_vals[i];
        if (a_vals[i] <= max_range && a_vals[i] > 0) {
            present_in_a[a_vals[i]] = true;
        }
    }
    
    for (int i = 0; i < m; i++) cin >> b_vals[i];

    long long alice_lcm = 1;
    for (int i = 1; i <= max_range; i++) {
        if (present_in_a[i]) {
            alice_lcm = get_safe_lcm(alice_lcm, (long long)i, (long long)max_range);
            if (alice_lcm > max_range) break;
        }
    }

    vector<bool> is_divisible(max_range + 1, false);
    for (int i = 1; i <= max_range; i++) {
        if (present_in_a[i]) {
            for (int j = i; j <= max_range; j += i) {
                is_divisible[j] = true;
            }
        }
    }

    int alice_score = 0, bob_score = 0, shared = 0;
    for (int x : b_vals) {
        bool fits_lcm = false;
        if (x <= max_range) {
            fits_lcm = (alice_lcm <= max_range && x % alice_lcm == 0);
        } else {
            if (alice_lcm <= max_range && x % alice_lcm == 0) fits_lcm = true;
        }
        
        if (fits_lcm) {
            alice_score++;
        } else if (x > max_range || !is_divisible[x]) {
            bob_score++;
        } else {
            shared++;
        }
    }

    bool wins;
    if (shared % 2 == 0) wins = (alice_score > bob_score);
    else wins = (alice_score >= bob_score);

    cout << (wins ? "Alice" : "Bob") << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}