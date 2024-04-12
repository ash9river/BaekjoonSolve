#include <iostream>
#include <vector>
#include <map>
#include <tuple>
#include <algorithm>
using namespace std;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n,c;
    cin>>n>>c;
    vector<int> v(n);
    map<int,int> table;
    map<int,int> m;
    vector<tuple<int,int,int>> ans(n);
    int ptr=0;
    for(int i=0;i<n;++i){
        cin>>v[i];
        if(table.count(v[i])>0){
            table[v[i]]=table[v[i]]+1;
        }
        else table[v[i]]=1;
        if(m.count(v[i])>0) continue;
        m.insert({v[i],ptr++});
    }
    for(int i=0;i<n;++i){
        ans[i]={-table[v[i]],m[v[i]],v[i]};
    }
    sort(ans.begin(),ans.end());
    for(tuple<int,int,int> k:ans) cout<<get<2>(k)<<" ";
}