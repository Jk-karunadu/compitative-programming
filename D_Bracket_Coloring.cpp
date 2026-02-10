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
        int n;
        cin >> n;
        string s;
        cin >> s;

        int balanced = 0;
        bool has_regular = false;
        bool has_inverted = false;
        vector<int> prefix_balance(n);
        
        int segment_start_char = 0; 

        for (int i = 0; i < n; i++)
        {
            // If we are at the start of a new balanced segment
            if (balanced == 0) {
                segment_start_char = s[i];
            }

            if (s[i] == '(')
                balanced++;
            else
                balanced--;

            if (segment_start_char == '(')
            {
                prefix_balance[i] = 1; // Color 1 for regular
                has_regular = true;
            }
            else
            {
                prefix_balance[i] = 2; // Color 2 for inverted
                has_inverted = true;
            }
        }

        // If the total balance isn't zero, it's impossible
        if (balanced != 0)
        {
            cout << -1 << "\n";
        }
        else 
        {
            // If we only used one type of segment, the answer is 1 color
            if (!(has_regular && has_inverted))
            {
                cout << 1 << "\n";
                for (int i = 0; i < n; i++)
                {
                    cout << 1 << (i == n - 1 ? "" : " ");
                }
                cout << "\n";
            }
            else 
            {
                // Otherwise, 2 colors are needed
                cout << 2 << "\n";
                for (int i = 0; i < n; i++)
                {
                    cout << prefix_balance[i] << (i == n - 1 ? "" : " ");
                }
                cout << "\n";
            }
        }
    }
    return 0;
}