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

        int count = 0;
        int i = 0;

        while (i < n)
        {
            if (vec[i] != 0)
            {
                count++;
                while (i < n && vec[i] != 0)
                {
                    i++;
                }
            }
            else
            {
                while (i < n && vec[i] == 0)
                {
                    i++;
                }
            }
        }

       
        cout << min(count, 2) << endl;
    }

    return 0;
}
