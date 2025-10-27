#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        string s;
        cin >> s;

        int l = 0;
        int r = n - 1;
        while (l < r)
        {
            if (s[l] == '0' && s[r] == '1' || s[l] == '1' && s[r] == '0')
            {
                l++;
                r--;
            }
            else
            {
                break;
            }
        }

        if (r < l)
        {
            cout << 0 << endl;
        }
        else if (r == l)
        {
            cout << 1 << endl;
        }
        else
        {
            cout << r - l + 1 << endl;
        }
    }
}