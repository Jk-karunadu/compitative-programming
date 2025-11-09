#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long a, b;
        cin >> a >> b;

      
        long long ans = LLONG_MAX;

        for (int i = 0; i < 32; i++)
        {
          
            long long count = i;
            long long new_b = b + i;

          
            if (new_b == 1)
            {
                continue; 
            }

            long long copy_a = a;

           
            while (copy_a > 0)
            {
               
                copy_a /= new_b;
                count++;
            }

           
            ans = min(ans, count);
        }

        cout << ans << "\n"; 
    }
    return 0;
}