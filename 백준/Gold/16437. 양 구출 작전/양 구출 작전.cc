#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define ll long long
using namespace std;
vector<vector<int>> graph;
vector<pair<ll,ll>> table; // shit, wooohhh
ll dfs(int src){
    if(graph[src].size()==0){
        return table[src].first;
    }
    ll tmp=0;
    for(int i=0;i<graph[src].size();++i){
        int nxt=graph[src][i];
        tmp+=dfs(nxt);
    }
    if(tmp-table[src].second>0){
        table[src].first+=tmp-table[src].second;
    }
    return table[src].first;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    graph.resize(n+1,vector<int>());
    table.resize(n+1,pair<ll,ll>({0,0}));
    char t;
    ll a,p;
    for(int i=2;i<=n;++i){
        cin>>t>>a>>p;
        if(t=='W'){
            table[i]={0,a};
        }
        else{
            table[i]={a,0};
        }
        graph[p].push_back(i);
    }
    cout<<dfs(1);
    
}