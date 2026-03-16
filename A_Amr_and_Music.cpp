#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    if (!(cin >> n >> k)) return 0;

    // Use a pair to store {value, original_index}
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first;
        a[i].second = i + 1; // Store 1-based index
    }

    // Sort based on the value (a[i].first)
    sort(a.begin(), a.end());

    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (k >= a[i].first)
        {
            k -= a[i].first;
            ans.push_back(a[i].second);
        }
        else
        {
            
            break;
        }
    }

    // Output the count
    cout << ans.size() << endl;
    
    // Output the original indices
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << (i == ans.size() - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}