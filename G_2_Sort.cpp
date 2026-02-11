#include <bits/stdc++.h>
using namespace std;

int solve(const vector<long long> &arr, int i, vector<int> &memo)
{
    if (i == 0)
        return 1;
    if (memo[i] != -1)
        return memo[i];

    if (arr[i-1] < 2LL * arr[i])
    {
        memo[i] = 1 + solve(arr, i - 1, memo);
    }
    else
    {
        memo[i] = 1;
    }
    return memo[i];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<long long> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        vector<int> memo(n, -1);

        for (int i = 0; i < n; i++)
        {
            solve(a, i, memo);
        }

        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (memo[i] >= k + 1)
            {
                count++;
            }
        }

        cout << count << "\n";
    }
}