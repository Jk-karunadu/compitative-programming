#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    ll sum = 0;
    int mx = 0;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        sum = sum + x;
        mx = max(mx, x);
    }

    if(sum%2 != 0 || mx > sum-mx){
        cout<<"NO";
    }
    else{
        cout<<"YES"<<endl;
    }
    return 0;
}