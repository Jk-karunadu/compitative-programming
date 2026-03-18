#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            if (i % 2 != x % 2)
            {
                count++;
            }
        }

        if(count%2 == 0){
            cout<<count/2<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }

    return 0;
}