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

        for (int i = 0; i < n; i++)
        {
            cin >> vec[i];
        }

        int p, q, r;
        bool found = false;
        ;

        for (int i = 1; i < n - 1; i++)
        {
            if (vec[i] > vec[i - 1] && vec[i] > vec[i + 1])
            {
                p = i - 1;
                q = i;
                r = i + 1;
                found = true;
                break;
            }
        }

        if (found)
        {
            cout << "YES" << endl;

            cout << p+1 << " " << q+1 << " " << r+1 << endl;
        }
        else
        {

            cout<<"NO"<<endl;
        }
    }
}