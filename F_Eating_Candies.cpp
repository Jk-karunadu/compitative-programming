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
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        int l = 0;
        int h = n - 1;
        long long left_sum = 0; // Use long long for sums
        long long right_sum = 0;
        int ans = 0; // ans is the count of elements

      

        while (l <= h)
        {
            if (left_sum == right_sum)
            {
               
                ans = l + (n - 1 - h);
                
                // If we are at the last element, eat it and stop.
                if (l == h) {
                    left_sum += a[l];
                    l++;
                }
                // Otherwise, eat from both sides to find the next valid state
                else {
                    left_sum += a[l];
                    l++;
                    right_sum += a[h];
                    h--;
                }
            }
            else if (left_sum < right_sum)
            {
                // Left side needs to catch up
                left_sum += a[l];
                l++;
            }
            else // left_sum > right_sum
            {
                // Right side needs to catch up
                right_sum += a[h];
                h--;
            }
        }
        
      
        // (e.g., all elements were eaten), we need to record this state.
        if (left_sum == right_sum)
        {
            ans = l + (n - 1 - h); // This will be 'n'
        }

        cout << ans << "\n"; // Added the missing print statement
    }
    return 0; // Added return 0
}