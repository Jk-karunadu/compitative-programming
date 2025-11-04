#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin>>n;
        int an;
        cin >> an;
        for (int i = 1; i < n; i++)
        {
            int x;
            cin >> x;
            an = an&x;
        }

        cout<<an<<endl;
    }
}