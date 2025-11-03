#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        long long n;
        cin >> n;

        vector<long long> vec(n);
        for (int i = 0; i < n; i++)
        {
            cin >> vec[i];
        }

        long long count = 0;
        bool found = true;

       

      
        for (int j = n - 2; j >= 0; j--)
        {
            if (vec[j] < vec[j + 1])
                continue;

         
            while (vec[j] >= vec[j + 1] && vec[j] > 0)
            {
                vec[j] = floor(vec[j] / 2);
                count++;
            }

         
            if (vec[j] >= vec[j + 1])
            {
                found = false;
                break;
            }
        }

        if (found)
            cout << count << endl;
        else
            cout << -1 << endl;
    }

    return 0;
}
