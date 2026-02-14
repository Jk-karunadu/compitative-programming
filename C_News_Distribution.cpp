#include <bits/stdc++.h>
using namespace std;

vector<int> parent(1000000);
vector<int> sz(1000000, 1); 

int find_parent(int x)
{
    if (parent[x] == x)
    {
        return x;
    }
    return parent[x] = find_parent(parent[x]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        sz[i] = 1;
    }

    while (m--)
    {
        int k; 
        cin >> k;
        
        if (k == 0) continue; 

        int first_person;
        cin >> first_person;
        int p = find_parent(first_person);

        for (int i = 1; i < k; i++)
        {
            int next_person;
            cin >> next_person;
            int q = find_parent(next_person);

            if (p != q)
            {
                if (sz[p] < sz[q])
                {
                    swap(p, q);
                }
                parent[q] = p;
                sz[p] += sz[q];
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << sz[find_parent(i)] << (i == n ? "" : " ");
    }
    cout << endl;

    return 0;
}