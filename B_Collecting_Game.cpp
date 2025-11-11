#include<bits/stdc++.h>

using namespace std;



int main(){

    int t;

    cin>>t;

    while(t--){

        int n;

cin>>n;

vector<pair<long long,int>> vec(n);

vector<long long> prefix_sum(n);



for(int i = 0;i<n;i++){

int x;
cin>>x;
vec.push_back({x,i});

}



sort(vec.begin(),vec.end());

prefix_sum[0] = vec[0].first;

for(int i = 1;i<n;i++){

    prefix_sum[i] = vec[i].first + prefix_sum[i-1];

}

vector<pair<int,int>> ans(n);

ans[n-1].second = n-1;
ans[n-1].first  = vec[n-1].second;


for(int i = n-2;i>=0;i--){



    if(prefix_sum[i] >= vec[i+1].first){
        ans[i].first = vec[i].second;

        ans[i].second = ans[i+1].second;

    }else{

        ans[i].first = vec[i].second;
        ans[i].second = i;

    }



}



sort(ans.begin(),ans.end());

for(int i = 0;i<n;i++){
    cout<<ans[i].second<<" ";
}
cout<<endl;


    }

} 