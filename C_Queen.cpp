#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> c(n + 1);
    vector<vector<int>> adj(n + 1);
    vector<int> noresp;
    
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if (x != -1) {
            adj[x].push_back(i);
        }
        cin >> c[i];
        if (c[i] == 1)
        {
            noresp.push_back(i);
        }
    }

    vector<int> results;
    sort(noresp.begin(), noresp.end());
    
    for (int i = 0; i < noresp.size(); i++)
    {
        int x = noresp[i];
        bool can_delete = true; 
        
        for (int j = 0; j < adj[x].size(); j++)
        {
            int y = adj[x][j];
            if (c[y] == 0) 
            {
                can_delete = false;
                break;
            }
        }
        
        if (can_delete)
        {
            results.push_back(x);
        }
    }
    if (results.empty()) {
        cout << -1 << endl;
    } else {
        for (int i = 0; i < results.size(); i++) {
            cout << results[i] << (i == results.size() - 1 ? "" : " ");
        }
        cout << endl;
    }

    return 0;
}