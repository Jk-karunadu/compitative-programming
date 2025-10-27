#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int m;
        cin >> m;
        int ans = INT_MIN;
        int count = 0;
        for (int i = 0; i < m; i++)
        {
            int x;
            cin >> x;
            if (x == 0)
            {
                count++;
                ans = max(ans, count);
            }
            else
            {
                count = 0;
            }
        }
        if (ans == INT_MIN)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << ans << endl;
        }
    }
}