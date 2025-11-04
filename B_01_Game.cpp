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

        stack<char> st;
        int count = 0;

        for (char c : s)
        {
            if (!st.empty() && st.top() != c)
            {
               
                st.pop();
                count++;
            }
            else
            {
                st.push(c);
            }
        }

        if (count % 2 == 0)
            cout << "NET" << endl;
        else
            cout << "DA" << endl;
    }
    return 0;
}
