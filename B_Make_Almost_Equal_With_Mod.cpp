#include <bits/stdc++.h>
using namespace std;

int main()
{
     int t;
    cin >> t;

    while (t--)
    {
        int n;
         cin >> n;
        vector<long long> vec(n);
         for (int i = 0; i < n; i++)
        {
            cin >> vec[i];
        
        }

        long long ans = 0;

       
     for (int i = 1; i < 60; i++)
        {
         set<long long> dist; // Set to store distinct values

            long long k = 1LL << i; // k = 2^i

           
         for (int j = 0; j < n; j++)
            {
               
                dist.insert(vec[j] % k);
                
            }

          
        if (dist.size() == 2)
            {
            ans = k;
        break; 
            
            }
        }

        cout << ans << endl;
        
    }
}