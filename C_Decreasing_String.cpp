#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int tc; cin >> tc;
	while(tc--) {
		string s;
		cin >> s;
		ll n = s.size(), pos;
		cin >> pos;

		string st;
		for(char &c : s) {
			while(!st.empty() && st.back() > c && pos > n) {
				st.pop_back();
				pos -= n; n--;
			}
			st.push_back(c);
		}

		while(pos > n) {
			st.pop_back(); pos -= n; n--;
		}

		cout << st[pos-1];
	}

	return 0;
}