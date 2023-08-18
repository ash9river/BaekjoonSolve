#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 200000000
using namespace std;
vector<vector<pair<int,int>>> graph;
int n,m;
int startNode,endNode;
void dijkstar(){
    vector<int> dist(n+1,INF);
    priority_queue<pair<int,int>> pq;
    dist[startNode]=0;
    vector<int> choice(n+1);
    pq.push({0,startNode});
    while(!pq.empty()){
        int cost=-pq.top().first;
        int now=pq.top().second;
        pq.pop();
        if(cost>dist[now]) continue;
        for(int i=0;i<graph[now].size();++i){
            int nxt=graph[now][i].second;
            int nextCost=cost+graph[now][i].first;
            if(nextCost<dist[nxt]){
                dist[nxt]=nextCost;
                pq.push({-nextCost,nxt});
                choice[nxt]=now;
            }
        }
    }
    cout<<dist[endNode]<<'\n';
    vector<int> ans;
    int ptr=endNode;
    ans.push_back(endNode);
    while(true){
        if(ptr==startNode) break;
        ans.push_back(choice[ptr]);
        ptr=choice[ptr];
    }
    cout<<ans.size()<<"\n";
    for(int i=ans.size()-1;i>=0;--i){
        cout<<ans[i]<<" ";
    }
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
    }
    cin>>startNode>>endNode;
    dijkstar();
}
