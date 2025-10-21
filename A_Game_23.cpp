#include<iostream>
using namespace std;


int get_count(int n , int m,int count){

    if(n == m) return count;
    if(n > m) return -1;
    int count1 = get_count(n*2,m,count+1);
    int count2 = get_count(n*3,m,count+1);
    if(count1 == -1) return count2;
    if(count2 == -1) return count1;
    return min(count1,count2);



}

int main(){
    int n,m;
    cin>>n>>m;
    if(n > m ) {
        cout<<-1;
        return 0;
    }

    cout<<get_count(n,m,0);

    return 0;


}

