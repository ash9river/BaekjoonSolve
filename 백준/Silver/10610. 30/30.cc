#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    string a;
    cin>>a;
    vector<int> v(a.size());
    for(int i=0;i<a.size();++i){
        v[i]=a[i]-'0';
    }
    sort(v.begin(),v.end(),greater<>());
    int sum=0;
    for(int i=0;i<v.size();++i){
        sum+=v[i];
    }
    if(sum%3==0&&v[v.size()-1]==0){
        for(int k:v) cout<<k;
    }else cout<<-1;
}