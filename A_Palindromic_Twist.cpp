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
        string s;
        cin >> s;
        int l = 0;
        int h = n - 1;
        bool found = true;
        while (l < h)
        {
            if (s[l] == s[h] || abs(s[h] - s[l]) == 2)
            {
                l++;
                h--;
            }
            else
            {
                found = false;
                break;
            }
        }
        if(found){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}