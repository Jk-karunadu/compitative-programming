#include <bits/stdc++.h>
using namespace std;

long long compute_linear(const vector<long long>& vals) {
  int m = vals.size();
  if (m <= 1) return 0;
  vector<int> lch(m, -1), rch(m, -1);
  stack<int> stk;
  for (int i = 0; i < m; ++i) {
    int prv = -1;
    while (!stk.empty() && vals[stk.top()] <= vals[i]) {
      prv = stk.top();
      stk.pop();
    }
    lch[i] = prv;
    if (!stk.empty()) {
      rch[stk.top()] = i;
    }
    stk.push(i);
  }
  vector<int> par(m, -1);
  for (int i = 0; i < m; ++i) {
    if (lch[i] != -1) par[lch[i]] = i;
    if (rch[i] != -1) par[rch[i]] = i;
  }
  long long c = 0;
  for (int i = 0; i < m; ++i) {
    if (par[i] != -1) {
      c += vals[par[i]];
    }
  }
  return c;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int test = 0; test < t; ++test) {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (auto& x : a) cin >> x;
    long long M = 0;
    for (auto x : a) M = max(M, x);
    vector<int> pos;
    for (int i = 0; i < n; ++i) {
      if (a[i] == M) pos.push_back(i);
    }
    int k = pos.size();
    long long sum_seg = 0;
    int pp = 0;
    for (int i = 0; i < k; ++i) {
      int j = (i + 1) % k;
      vector<long long> temp;
      if (j > i) {
        int st = pos[i] + 1;
        int en = pos[j] - 1;
        if (st > en) continue;
        for (int ii = st; ii <= en; ++ii) {
          temp.push_back(a[ii]);
        }
      } else {
        int st = pos[i] + 1;
        int en = n - 1;
        for (int ii = st; ii <= en; ++ii) {
          temp.push_back(a[ii]);
        }
        int st2 = 0;
        int en2 = pos[j] - 1;
        for (int ii = st2; ii <= en2; ++ii) {
          temp.push_back(a[ii]);
        }
      }
      if (temp.empty()) continue;
      pp++;
      sum_seg += compute_linear(temp);
    }
    long long ans = sum_seg + M * (pp + (long long)k - 1LL);
    cout << ans << '\n';
  }
  return 0;
}
