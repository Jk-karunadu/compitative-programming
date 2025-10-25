#include<iostream>
#include<vector>
using namespace std;

bool is_possible(string s1 , string s2){
    string temp = s1;

    // we only need to check limited times (since n*m ≤ 25)
    for(int i = 0; i <= 10; i++){
        if(temp.find(s2) != string::npos){
            return true;
        }
        temp += temp; // operation: append s1 to itself
    }

    return false;
}

int main(){
    int n;
    cin >> n;

    while(n--){
        int a,b;
        cin >> a >> b;

        string s1;
        cin >> s1;
        string s2;
        cin >> s2;

        // if already contains s2, no operation needed
        if(s1.find(s2) != string::npos){
            cout << 0 << endl;
            continue;
        }

        int count = 0;
        bool found = false;
        string temp = s1;

        // simulate operations
        for(int i = 0; i <= 10; i++){
            if(temp.find(s2) != string::npos){
                cout << count << endl;
                found = true;
                break;
            }
            temp += temp;
            count++;
        }

        if(!found){
            cout << -1 << endl;
        }
    }
    return 0;
}
