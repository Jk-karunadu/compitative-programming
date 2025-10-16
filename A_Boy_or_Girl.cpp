#include<iostream>
using namespace std;
int main(){
    
    string s;
    cin>>s;
    int count=0;
    int arr[26]={0};
    for(int i=0;i<s.length();i++){
        if(arr[s[i]-'a']==0){
            count++;
            arr[s[i]-'a']=1;
        }
    }
   
    if(count%2==0){
        cout<<"CHAT WITH HER!"<<endl;
    }
    else{
        cout<<"IGNORE HIM!"<<endl;
    }
    return 0;
}