#include <iostream>
#include <vector>
using namespace std;

bool check_front(vector<int> &a, int idx, int x)
{
    // check up to x elements before idx
    for (int i = idx - 1; i >= max(0, idx - x); i--)
    {
        if (a[i] <= a[idx])  // must be strictly greater
            return false;
    }
    return true;
}

bool check_back(vector<int> &a, int idx, int y)
{
    int n = a.size();
    // check up to y elements after idx
    for (int i = idx + 1; i <= min(n - 1, idx + y); i++)
    {
        if (a[i] <= a[idx])  // must be strictly greater
            return false;
    }
    return true;
}

int main()
{
    int n, x, y;
    cin >> n >> x >> y;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++)
    {
        if (check_front(a, i, x) && check_back(a, i, y))
        {
            cout << i + 1 << endl; // 1-based index
            return 0;
        }
    }

    return 0;
}
