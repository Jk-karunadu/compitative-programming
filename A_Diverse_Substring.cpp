#include<iostream>
using namespace std;

bool isdiverse(string s){
  int count[26] = {0};
  
  for(int i = 0;i<s.length();i++){
    count[s[i]-'a']++;
   
  }
    for(int i = 0;i<26;i++){
        if(count[i]>s.length()/2)
        return false;
    }
    return true;
}


int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
   for(int i = 0;i<n;i++){
    for(int j = i+1;j<n;j++){
        string check = s.substr(i,j-i+1);
        if(isdiverse(check)){
            cout<<"YES"<<endl;
            cout<<s.substr(i,j-i+1)<<endl;
            return 0;
    }
   }
    
}
    cout<<"NO"<<endl;
    return 0;
}