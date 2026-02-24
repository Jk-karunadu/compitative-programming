#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    
    long long prod = 1; 
    long long mod = 1e9 + 7;
    int n = s.length();
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'a') 
        {
            count++;
        }
        else if (s[i] == 'b') 
        {
            if (count > 0) {
                prod = (prod * (count + 1)) % mod;
                count = 0;
            }
        }
    }
    
    if (count > 0) {
        prod = (prod * (count + 1)) % mod;
    }

    cout << (prod - 1 + mod) % mod << endl;

    return 0;
}