#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <algorithm>
#define ll long long
using namespace std;
vector<vector<int>> graph;
vector<bool> visited;
int n,m,k,x;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>n>>m>>k>>x;
    graph.resize(n+1,vector<int>());
    visited.resize(n+1,false);
    int a,b;
    for(int i=0;i<m;++i){
        cin>>a>>b;
        graph[a].push_back(b);
    }
    queue<pair<int,int>> q;
    deque<int> ans;
    q.push({0,x});
    visited[x]=true;
    while(!q.empty()){
        int distance=q.front().first;
        int now=q.front().second;
        q.pop();
        if(distance==k) ans.push_back(now);
        for(int i=0;i<graph[now].size();++i){
            int nxt=graph[now][i];
            if(!visited[nxt]){
                visited[nxt]=true;
                q.push({distance+1,nxt});
            }
        }
    }
    if(ans.empty()) cout<<-1;
    else{
        sort(ans.begin(),ans.end());
        for(int k:ans) cout<<k<<"\n";
    }
}