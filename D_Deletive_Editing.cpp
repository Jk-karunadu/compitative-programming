#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s, target;
        cin >> s >> target;

        int i = s.size() - 1;
        int j = target.size() - 1;
        bool found = true;
        unordered_map<char, bool> m;

        while (i >= 0 && j >= 0)
        {
            if (s[i] == target[j])
            {
               
                if (!m[s[i]])
                {
                    j--;
                }
                else
                {
                    found = false;
                    break;
                }
            }
            else
            {
                
                m[s[i]] = true;
            }
            i--;
        }

        if (j < 0 && found)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
