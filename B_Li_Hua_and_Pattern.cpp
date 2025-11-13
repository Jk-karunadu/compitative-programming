#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Add fast I/O
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        long long k;
        cin >> n >> k;

        vector<int> vec(n * n);
        for (int i = 0; i < n * n; i++)
        {
            cin >> vec[i];
        }

        int mismatch_pairs = 0;
        
       
        for (int i = 0; i < (n * n) / 2; i++)
        {
          
            if (vec[i] != vec[n * n - 1 - i])
            {
                mismatch_pairs++;
            }
        }

       
        if (k < mismatch_pairs)
        {
            cout << "NO\n";
            continue; // Not enough operations
        }

        
        long long remaining_k = k - mismatch_pairs;

       
        if (n % 2 == 1)
        {
            cout << "YES\n";
        }
        else
        {
            
            if (remaining_k % 2 == 0)
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
    }
    return 0; // Added return 0
}