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
        long long l, r;
        cin >> n >> l >> r;

        vector<long long> a(n); // Stores the answer
        bool possible = true;

        for (int i = 1; i <= n; i++)
        {
           
            long long i_ll = i; 
            
            // k = ceiling(l / i)
            long long k = (l + i_ll - 1) / i_ll;
            long long value = k * i_ll;

            if (value > r)
            {
                possible = false;
                break; 
            }
            else
            {
                a[i - 1] = value; 
            }
        }

        if (possible)
        {
            cout << "YES\n"; // Use \n for faster I/O
            for (int i = 0; i < n; i++)
            {
                cout << a[i] << " ";
            }
            cout << "\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0; // Added return 0
}