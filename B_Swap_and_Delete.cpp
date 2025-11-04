#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        int zeros = 0;
        int ones = 0;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '0')
                zeros++;
            if (s[i] == '1')
                ones++;
        }

        if (zeros == ones)
        {
            cout << 0 << endl;
        }
        else
        {
            
            for (int i = 0; i < s.length(); i++)
            {
                if (s[i] == '1')
                {
                    if (zeros == 0)
                    {
                       break;
                    }
                    else
                    {
                        zeros--;
                    }
                }
                else{
                    if(ones == 0){
                       break;
                    }
                    else{
                        ones--;
                    }
                }
            }

            cout<<zeros+ones<<endl;
        }
    }
}