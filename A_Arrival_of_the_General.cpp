#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int max=a[0],min=a[0],maxi=0,mini=0;
    for(int i=0;i<n;i++){
        if(a[i]>max){
            max=a[i];
            maxi=i;
        }
        if(a[i]<=min){
            min=a[i];
            mini=i;
        }
    }
    if(maxi>mini){
        cout<<maxi+(n-1-mini)-1;
    }
    else{
        cout<<maxi+(n-1-mini);
    }
    return 0;
}