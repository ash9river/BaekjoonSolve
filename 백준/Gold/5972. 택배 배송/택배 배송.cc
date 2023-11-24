#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int n,m;
vector<vector<pair<int,int>>> graph;
int cache[50001];
void djik(){
    priority_queue<pair<int,int>> q;
    fill(&cache[0],&cache[50001],987654321);
    q.push({0,1});
    cache[1]=0;
    while(!q.empty()){
        int cost=-q.top().first;
        int now=q.top().second;
        q.pop();
        for(int i=0;i<graph[now].size();++i){
            int nxt=graph[now][i].second;
            int nxtCost=graph[now][i].first+cost;
            if(nxtCost>=cache[nxt]) continue;
            q.push({-nxtCost,nxt});
            cache[nxt]=nxtCost;
        }
    }
    cout<<cache[n];
}
int main(){
	cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    graph.resize(n+1,vector<pair<int,int>>());
    int a,b,c;
    for(int i=0;i<m;++i){
        cin>>a>>b>>c;
        graph[a].push_back({c,b});
        graph[b].push_back({c,a});
    }
    for(int i=1;i<=n;++i){
        sort(graph[i].begin(),graph[i].end());
    }
    djik();
}