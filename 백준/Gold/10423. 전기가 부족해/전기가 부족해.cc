#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector<bool> dosi;
vector<int> table;
vector<vector<pair<int,int>>> graph;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n,m,k;
    cin>>n>>m>>k;
    dosi.resize(n+1,false);
    table.resize(n+1);
    int a,b,c;
    for(int i=0;i<k;++i){
        cin>>a;
        table[i]=a;
    }
    graph.resize(n+1,vector<pair<int,int>>());
    for(int i=0;i<m;++i){
        cin>>a>>b>>c;
        graph[a].push_back({c,b});
        graph[b].push_back({c,a});
    }
    for(int i=1;i<=n;++i) sort(graph[i].begin(),graph[i].end());
    int rslt=0;
    priority_queue<pair<int,int>> q;
    for(int i=0;i<k;++i){
        q.push({0,table[i]});
    }
    while(!q.empty()){
        int cost=-q.top().first;
        int now=q.top().second;
        q.pop();
        if(dosi[now]) continue;
        dosi[now]=true;
        rslt+=cost;
        for(int i=0;i<graph[now].size();++i){
            int nxtCost=graph[now][i].first;
            int nxt=graph[now][i].second;
            if(!dosi[nxt]){
                q.push({-nxtCost,nxt});
            }
        }
    }
    cout<<rslt;
}