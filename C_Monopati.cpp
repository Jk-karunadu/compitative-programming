#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <climits>

using namespace std;

long long solve()
{
    int n;
    cin >> n;
    int max_val = 2 * n;

    vector<int> top(n + 1), bot(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> top[i];
    for (int i = 1; i <= n; i++)
        cin >> bot[i];

    vector<int> prefix_min_top(n + 1);
    vector<int> prefix_max_top(n + 1);
    prefix_min_top[1] = top[1];
    prefix_max_top[1] = top[1];
    for (int i = 2; i <= n; i++)
    {
        prefix_min_top[i] = min(prefix_min_top[i - 1], top[i]);
        prefix_max_top[i] = max(prefix_max_top[i - 1], top[i]);
    }

    vector<int> suffix_min_bot(n + 2, INT_MAX);
    vector<int> suffix_max_bot(n + 2, INT_MIN);
    for (int i = n; i >= 1; i--)
    {
        suffix_min_bot[i] = min(suffix_min_bot[i + 1], bot[i]);
        suffix_max_bot[i] = max(suffix_max_bot[i + 1], bot[i]);
    }

    vector<pair<int, int>> events;
    for (int k = 1; k <= n; k++)
    {
        int Ak = min(prefix_min_top[k], suffix_min_bot[k]);
        int Bk = max(prefix_max_top[k], suffix_max_bot[k]);

        events.emplace_back(Bk, Ak);
    }

    sort(events.begin(), events.end());

    long long total_ans = 0;
    int max_A_so_far = 0;
    int event_pointer = 0;
    int num_events = events.size();

    for (int r = 1; r <= max_val; r++)
    {

        while (event_pointer < num_events && events[event_pointer].first <= r)
        {

            max_A_so_far = max(max_A_so_far, events[event_pointer].second);
            event_pointer++;
        }

        total_ans += min(r, max_A_so_far);
    }

    return total_ans;
}

int main()
{
  
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
       
        cout << solve() << '\n';
    }
    return 0;
}