#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Added fast I/O
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        vector<int> b(n);

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        
        // Use long long to prevent overflow
        long long mx_till = 0; // Start at 0 (assuming b[i] >= 0)
        long long mx = 0;      // Start at 0 for the k=0 case
        long long sum = 0;

        // Handle the k=0 case separately
        if (k == 0) {
            cout << 0 << "\n";
            continue;
        }
        
        // We only need to iterate up to min(n, k)
        int limit = min(n, k); 

        for (int i = 0; i < limit; i++)
        {
            sum = sum + a[i];
            mx_till = max(mx_till, (long long)b[i]); // Keep track of max b
            
            long long remaining_steps = k - i - 1;
            long long current_score = sum + mx_till * remaining_steps;
            
            // On the first iteration (i=0), mx is 0.
            // We set mx to the first score calculated.
            if (i == 0) {
                mx = current_score;
            } else {
                mx = max(mx, current_score);
            }
        }
        cout << mx << "\n"; // Use \n for faster I/O
    }
    return 0; // Added return
}