#include<iostream>
using namespace std;
int main(){
    int a , b, c;
    cin>>a>>b>>c;
   int mx = max(a,max(b,c));
   int mn = min(a,min(b,c));

   int mid;
   if(mx == a && mn == b) mid = c;
   else if(mx == a && mn == c) mid = b;
    else if(mx == b && mn == a) mid = c;
    else if(mx == b && mn == c) mid = a;
    else if(mx == c && mn == a) mid = b;
    else mid = a;

    int pre = mid-1;
    int nxt = mid+1;
    int ans = min(1 + abs(pre-mn) + abs(pre-mx), 1 + abs(nxt-mn) + abs(nxt-mx));
    ans = min(ans,abs(mn-mid) + abs(mx-mid));
    cout<<ans<<endl;
    return 0;
}