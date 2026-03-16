#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int l = 3;
        int r = x + 2;
        int f = 1;
        if(n < 3){
            cout<<1<<endl;
            continue;
        }

        while (!(n >= l && n <= r))
        {
            l = l + x;
            r = r + x;
            f++;
        }

        cout << f + 1 << endl;
    }

    return 0;
}