#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    vector<pair<int,int>> v(n);
    int sum=0;
    int a,b;
    for(int i=0;i<n;++i){
        cin>>v[i].first;
    }
    for(int i=0;i<n;++i){
        cin>>v[i].second;
    }
    for(int i=0;i<n;++i){
        if(v[i].first>v[i].second) sum+=v[i].first-v[i].second;
    }
    cout<<sum;
}