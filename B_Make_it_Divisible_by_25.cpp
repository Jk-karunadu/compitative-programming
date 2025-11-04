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
        bool zero_occured = false;
        bool five_occured = false;
        long long count = 0;

        while (n > 0)
        {
            int d = n % 10;

            n = n / 10;
            if (d == 0)
            {
                if (zero_occured)
                {
                    cout << count-1<< endl;
                    break;
                }
                else
                {
                    zero_occured = true;
                }
            }
            else if (d == 5)
            {

                if (zero_occured)
                {
                    cout << count-1 << endl;
                    break;
                }
                else
                {
                    five_occured = true;
                }
            }
            else if (d == 2)
            {

                if (five_occured)
                {
                    cout << count-1 << endl;
                    break;
                }
            }
            else if (d == 7)
            {

                if (five_occured)
                {
                    cout << count-1 << endl;
                    break;
                }
            }

            count++;
        }
    }
}