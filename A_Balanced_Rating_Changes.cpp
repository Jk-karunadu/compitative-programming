#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;
    
    vector<int> ans;
    bool up = true; 
    
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        
        if (x % 2 == 0)
        {
            ans.push_back(x / 2);
        }
        else
        {
            if (up)
            {
                if (x > 0) ans.push_back((x + 1) / 2);
                else ans.push_back((x + 0) / 2);
            }
            else
            {
                if (x > 0) ans.push_back((x + 0) / 2);
                else ans.push_back((x - 1) / 2); 
            }
            up = !up;
        }
    }

    for(int i = 0; i < n; i++){
        cout << ans[i] << "\n";
    }
    
    return 0;
}