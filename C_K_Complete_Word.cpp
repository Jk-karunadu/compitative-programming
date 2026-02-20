#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;
        
        vector<vector<int>> vec(k, vector<int>(26, 0));

        for (int i = 0; i < n; i++)
        {
            int j = i % k;
            vec[j][s[i] - 'a']++;
        }

        int ans = 0;
        for (int i = 0; i < (k + 1) / 2; i++)
        {
            int j = k - 1 - i;
            int mx = 0;
            int total_in_group = 0;

            for (int c = 0; c < 26; c++)
            {
                int current_freq;
                if (i == j) {
                    current_freq = vec[i][c];
                } else {
                    current_freq = vec[i][c] + vec[j][c];
                }
                mx = max(mx, current_freq);
                total_in_group += current_freq;
            }
            ans += (total_in_group - mx);
        }

        cout << ans << endl;
    }
    return 0;
}