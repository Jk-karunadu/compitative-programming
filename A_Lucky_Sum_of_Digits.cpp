#include<iostream>
using namespace std;
int helper(int n,int d){
    if(n == 0) return d;
    if(n < 0) return 1e9;
    return min(helper(n-7,d*10+7),helper(n-4,d*10+4));
}

int main(){
    int n;
    cin >> n;
   int ans1 = helper(n-7,7);
   int ans2 = helper(n-4,4);
   if(ans1 == 1e9 && ans2 == 1e9){
       cout<<-1<<endl;
       return 0;
   }
   cout<<min(ans1,ans2)<<endl;
   return 0;
   
}