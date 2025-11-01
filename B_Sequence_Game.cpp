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

        vector<int> seq;
        int prev;
        cin >> prev;
        seq.push_back(prev);
        for (int i = 1; i < n; i++)
        {
            int x;
            cin >> x;
            if (prev <= x)
            {
                seq.push_back(x);
                prev = x;
            }
            else
            {
                seq.push_back(x);
                seq.push_back(x);
                prev = x;
            }
        }

        cout << seq.size() << endl;
        for (int i = 0; i < seq.size(); i++)
        {
            cout << seq[i] << " ";
        }
        cout << endl;
    }
}