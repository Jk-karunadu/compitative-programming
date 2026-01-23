#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--)
        {
            int n, h, l;
            cin >> n >> h >> l;

            int mn = min(h, l);
            int mx = max(h, l);

            int countA = 0; 
            int countB = 0; 

            for (int i = 0; i < n; i++)
            {
                int val;
                cin >> val;
                
                if (val <= mn) {
                    countA++;
                } else if (val <= mx) {
                    countB++;
                }
            }

            if (countA <= countB) {
                cout << countA << endl;
            } else {
                int pairs = countB + (countA - countB) / 2;
                cout << pairs << endl;
            }
        }
    }
    return 0;
}