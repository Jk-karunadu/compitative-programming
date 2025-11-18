// #include <bits/stdc++.h>

// using namespace std;

// int main()
// {
//    int t;
//    cin >> t;

//    while (t--)
//    {
//       int n, s;
//       cin >> n >> s;

//       vector<int> v(n);

//       for (int i = 0; i < n; i++)
//          cin >> v[i]; //? O(N)

//       int len = -1; 

//       map<int, int> mp;

//       mp[0] = -1;

//       int sum = 0;

//       for (int i = 0; i < n; i++)
//       {
//          sum += v[i];

//          if (mp.count(sum - s))
//          {
//             len = max(len, i - mp[sum - s]);
//          }

//          if (!mp.count(sum))
//          {
//             mp[sum] = i; //? O(log N)
//          }
//       } //? O(N log N)

//       if (len == -1)
//       {
//          cout << "-1\n";
//       }
//       else
//       {
//          cout << (n - len) << "\n";
//       }
//    }
// }


#include <bits/stdc++.h>
using namespace std;

int binary_first_occurance(int val, int r, vector<int> &prefix) {
    int l = 0;
    int ans = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (prefix[mid] == val) {
            ans = mid;
            r = mid - 1;
        }
        else if (prefix[mid] < val) l = mid + 1;
        else r = mid - 1;
    }
    return ans;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, s;
        cin >> n >> s;

        vector<int> vec(n);
        for (int i = 0; i < n; i++)
            cin >> vec[i];

        vector<int> prefix(n);
        prefix[0] = vec[0];
        for (int i = 1; i < n; i++)
            prefix[i] = prefix[i - 1] + vec[i];

        int total = prefix[n - 1];

        if (s > total) {
            cout << -1 << endl;
            continue;
        }
        if (s == total) {
            cout << 0 << endl;
            continue;
        }

        int ans = INT_MAX;

        // For each starting point i
        for (int i = 0; i < n; i++) {

            // Binary search for the farthest pos such that sum(i..pos) <= s
            int l = i, r = n - 1, pos = -1;

            while (l <= r) {
                int mid = (l + r) / 2;

                int subSum = prefix[mid] - (i ? prefix[i - 1] : 0);

                if (subSum <= s) {
                    pos = mid;
                    l = mid + 1;
                } 
                else r = mid - 1;
            }

            // EXACT CF Logic: skip invalid or not equal to s
            if (pos == -1) continue;

            int finalSum = prefix[pos] - (i ? prefix[i - 1] : 0);

            if (finalSum != s) continue;

            // length of subarray
            int len = pos - i + 1;

            // minimum removals
            ans = min(ans, n - len);
        }

        if (ans == INT_MAX) ans = -1;

        cout << ans << endl;
    }

    return 0;
}
