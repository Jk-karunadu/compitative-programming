#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> p[i];
    }

    vector<int> suff_max_idx(n);
    suff_max_idx[n - 1] = n - 1;
    for (int i = n - 2; i >= 0; --i)
    {
        if (p[i] > p[suff_max_idx[i + 1]])
        {
            suff_max_idx[i] = i;
        }
        else
        {
            suff_max_idx[i] = suff_max_idx[i + 1];
        }
    }
    int cur_min = p[0];
    for (int i = 0; i < n - 1; ++i)
    {
        cur_min = min(cur_min, p[i]);
        if (cur_min > p[suff_max_idx[i + 1]])
        {
            cout << "No" << endl;
            return;
        }
    }

    cout << "Yes" << endl;

    stack<int> s;
    vector<int> roots;

    for (int i = 0; i < n; ++i)
    {

        while (!s.empty() && p[s.top()] > p[i])
        {
            s.pop();
        }

        if (!s.empty())
        {

            cout << p[s.top()] << " " << p[i] << "\n";
        }
        else
        {

            roots.push_back(i);
        }

        s.push(i);
    }

    for (size_t k = 0; k < roots.size() - 1; ++k)
    {
        int u_idx = roots[k];
        int next_segment_start = roots[k + 1];

        int v_idx = suff_max_idx[next_segment_start];
        cout << p[u_idx] << " " << p[v_idx] << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}