#include <iostream>
using namespace std;

int main()
{
    int n;

    cin >> n;

    int c = 1;
    string s;
    cin >> s;

    for (int i = 0; i < n; i++)
    {
        if ((i + 1) == c * (c + 1) / 2)
        {
            cout << s[i];
            c++;
        }
       
    }
    return 0;
}