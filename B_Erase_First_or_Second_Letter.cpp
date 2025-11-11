#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int ans = 0;
        int num_unique = 0;
        unordered_map<char, int> m;
        vector<int> dis(n);

        for (int i = 0; i < n; i++)
        {
            m[s[i]]++;
            if(m[s[i]] == 1){
                ans++;
            }
            dis[i] = ans;

        }
        int final_ans = 0;

        for(int i = 0;i<n;i++){
            final_ans = final_ans + dis[i];

        }

        cout << final_ans << endl;
    }
}
