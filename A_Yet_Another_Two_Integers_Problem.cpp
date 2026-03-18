#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;

        cin >> a >> b;

        int tens = abs(b - a) / 10;

        if (b >= a)
        {
            if (a + tens * 10 == b)
            {
                cout << tens << endl;
            }
            else
            {
                cout << tens + 1 << endl;
            }
        }
        else
        {
            if (a - tens * 10 == b)
            {
                cout << tens << endl;
            }
            else
            {
                cout << tens + 1 << endl;
            }
        }
    }

    return 0;
}