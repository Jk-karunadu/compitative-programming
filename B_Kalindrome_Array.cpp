#include <bits/stdc++.h>
using namespace std;

bool is_palindrome(int l, int h, int val_to_delete, const vector<int>& a) {
    while (l < h) {
        if (a[l] == a[h]) {
            l++;
            h--;
        } else if (a[l] == val_to_delete) {
            l++;
        } else if (a[h] == val_to_delete) {
            h--;
        } else {
            return false;
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        int l = 0;
        int h = n - 1;
        bool found = true; 

        while (l < h)
        {
            if (a[l] == a[h])
            {
                l++;
                h--;
            }
            else
            {
                bool can_del_l = is_palindrome(l, h, a[l], a);
                bool can_del_h = is_palindrome(l, h, a[h], a);

                found = can_del_l || can_del_h;
                
                break;
            }
        }

        if (found) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0; 
}