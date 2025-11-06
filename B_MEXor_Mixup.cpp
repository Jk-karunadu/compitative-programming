#include <bits/stdc++.h>
using namespace std;


int xorTillNminus1(int n)
{
    int m = n - 1;
    if (m % 4 == 0) return m;
    else if (m % 4 == 1) return 1;
    else if (m % 4 == 2) return m + 1;
    else return 0;
}

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int a, b;
        cin >> a >> b;

        int prefix = xorTillNminus1(a);  
        int ans;

        if (prefix == b)
            ans = a;          
        else if ((prefix ^ b) == a)
            ans = a + 2;       
        else
            ans = a + 1;     

        cout << ans << "\n";
    }
}
