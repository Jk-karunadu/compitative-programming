#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string p, h;
        cin >> p >> h;
        
        unordered_map<char, int> om;
        for (auto a : p)
        {
            om[a]++;
        }

        bool found = false;

        for (int i = 0; i <= (int)h.size() - (int)p.size(); i++)
        {
            unordered_map<char, int> m = om; 
            int count = 0;

            for (int j = i; j < i + p.size(); j++)
            {
                if (m.find(h[j]) != m.end() && m[h[j]] > 0)
                {
                    m[h[j]]--;
                    count++;
                }
                else
                {
                    break;
                }
            }

            if (count == p.size())
            {
                found = true;
                break;
            }
        }

        if (found) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}