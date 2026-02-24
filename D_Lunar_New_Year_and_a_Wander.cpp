#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        if (x == y) continue; 
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> vis(n + 1, 0);
    vector<int> result;

    pq.push(1);
    vis[1] = 1;

    while (!pq.empty())
    {
        int curr = pq.top();
        pq.pop();
        
        result.push_back(curr);

        for (auto neighbor : adj[curr])
        {
            if (!vis[neighbor])
            {
                vis[neighbor] = 1;
                pq.push(neighbor);
            }
        }
    }
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << (i == result.size() - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}