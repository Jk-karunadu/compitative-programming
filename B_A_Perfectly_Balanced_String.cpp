#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;

        unordered_map<char, int> m;
        int i;

        for (i = 0; i < s.length(); i++)
        {
            if (m.count(s[i]) == 0)
            {
                m[s[i]]++;
            }
            else
            {
                break;
            }
        }

        bool found = true;

        for(int j = i;j<s.length();j++){
            if(s[j] != s[j-i]){
                found = false;
                break;
            }
        }


        if (found)
        {
            cout << "YES" << "\n";
        }
        else
        {
            cout << "NO" << "\n";
        }
    }
    return 0;
}