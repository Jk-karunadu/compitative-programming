#include <bits/stdc++.h>
using namespace std;

int main()
{
  

    int t;
    cin >> t;

    while (t--)
    {
        int n, q;
        cin >> n >> q; 

        vector<long long> a(n);
        vector<int> b(q);

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        for (int i = 0; i < q; i++)
        {
            cin >> b[i];
        }
        
        int prev = 31;

        for (int i = 0; i < q; i++)
        {
          
            if (b[i] >= prev)
            {
                continue;
            }

           
            long long x = static_cast<long long>(pow(2, b[i]));
            long long to_add = static_cast<long long>(pow(2, b[i] - 1));

            for (int j = 0; j < n; j++)
            {
                if (a[j] % x == 0)
                {
                    
                    a[j] = a[j] + to_add;
                }
            }
           
            prev = b[i];
        }

        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }

        cout << "\n";
    }
    return 0;
}