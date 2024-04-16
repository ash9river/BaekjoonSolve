#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector<vector<int>> graph;
pair<int,int> ans={987654321,0};
int n,m;
void bfs(int src){
    vector<bool> visited(n+1,false);
    visited[src]=true;
    queue<pair<int,int>> q;
    int tmp=0;
    q.push({0,src});
    while(!q.empty()){
        int dis=q.front().first;
        int now=q.front().second;
        tmp+=dis;
        q.pop();
        for(int i=1;i<=n;++i){
            if(!visited[i]&&graph[now][i]==1){
                visited[i]=true;
                q.push({dis+1,i});
            }
        }
    }
    if(ans.first>tmp){
        ans={tmp,src};
    }
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    graph.resize(n+1,vector<int>(n+1));
    int a,b;
    for(int i=0;i<m;++i){
        cin>>a>>b;
        graph[a][b]=1;
        graph[b][a]=1;
    }
    for(int i=1;i<=n;++i){
        bfs(i);
    }
    cout<<ans.second;
}