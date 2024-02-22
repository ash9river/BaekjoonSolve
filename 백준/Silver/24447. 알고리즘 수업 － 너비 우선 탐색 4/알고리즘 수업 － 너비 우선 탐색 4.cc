#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n,m,r;
    cin>>n>>m>>r;
    vector<vector<int>> graph(n+1,vector<int>());
    vector<long long> visited(n+1,-1);//depth
    vector<long long> table(n+1,0);//order
    int a,b;
    for(int i=0;i<m;++i){
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    queue<int> q;
    q.push(r);
    int ptr=1;
    table[r]=ptr++;
    visited[r]=0;
    for(int i=1;i<=n;++i){
        sort(graph[i].begin(),graph[i].end());
    }
    while(!q.empty()){
        int now=q.front();
        int depth=visited[now];
        q.pop();
        for(int i=0;i<graph[now].size();++i){
            int nxt=graph[now][i];
            if(visited[nxt]!=-1) continue;
            visited[nxt]=depth+1;
            table[nxt]=ptr++;
            q.push(nxt);
        }
    }
    long long ans=0;
    for(int i=1;i<=n;++i){
        if(visited[i]!=-1){
            ans+=table[i]*visited[i];
        }
    }
    cout<<ans;
}