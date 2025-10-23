#include<iostream>
using namespace std;

bool is_all(string s){
   
    for(int i = 1; i < s.length(); i++){
        if(islower(s[i]))
            return false;
    }
    return true;
}

int main(){
    string s;
    cin >> s;

  if(is_all(s) )
        for(int i = 0; i < s.length(); i++){
            if(isupper(s[i]))
                s[i] = tolower(s[i]);
            else
                s[i] = toupper(s[i]);
        }
    cout << s << endl;
    return 0;
}