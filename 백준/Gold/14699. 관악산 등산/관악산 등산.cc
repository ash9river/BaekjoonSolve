#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;//1%틀
int n,m;
vector<vector<int>> graph;
vector<int> height; 
vector<int> dp;
int dfs(int src){
    int& ret=dp[src];
    if(ret!=-1) return ret;
    ret=1;
    for(int i=0;i<graph[src].size();++i){
        int nxt=graph[src][i];
        if(height[nxt]>height[src]){
            ret=max(ret,dfs(nxt)+1);
        }
    }
    return ret;
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    height.resize(n+1);
    graph.resize(n+1,vector<int>());
    dp.resize(n+1,0);
    fill(dp.begin(),dp.end(),-1);
    for(int i=1;i<=n;++i){
        cin>>height[i];
    }
    int a,b;
    for(int i=0;i<m;++i){
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i=1;i<=n;++i){
        cout<<dfs(i)<<"\n";
    }
}