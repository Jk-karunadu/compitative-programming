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
        vector<int> vec(n);
        int idx = -1;
        int mx = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            cin >> vec[i];
            if (mx < vec[i])
            {
                idx = i;
                mx = vec[i];
            }
        }
        if (n > 1 && idx != 0)
        {
            int t = vec[idx];
            vec[idx] = vec[0];
            vec[0] = t;
        }

        for (int i = 0; i < n; i++)
        {
            cout << vec[i] << " ";
        }
        cout << endl;
    }
}