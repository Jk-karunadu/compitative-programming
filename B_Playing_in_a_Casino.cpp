#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<long long>> vec(n, vector<long long>(m));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> vec[i][j];
            }
        }

        // The 'sum' vector is no longer needed for this logic
        
        long long final_sum = 0;

        
        for (int j = 0; j < m; j++)
        {
            
            vector<long long> temp_col(n);
            for (int i = 0; i < n; i++)
            {
                temp_col[i] = vec[i][j];
            }

            
            sort(temp_col.begin(), temp_col.end());
            for (int i = 0; i < n; i++)
            {
                
                final_sum = final_sum + (2LL * i - n + 1) * temp_col[i];
            }
        }

        cout << final_sum << endl;
    }
    return 0; 
}