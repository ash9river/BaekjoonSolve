#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<bool> visited(5000001);
vector<vector<int>> v;
int gae;
void dfs(int start,int depth){
    if(visited[start]) return;
    visited[start]=true;
    bool state=false;
    for(int i=0;i<v[start].size();++i){
        int nxt=v[start][i];
        if(!visited[nxt]){
            state=true;
            dfs(nxt,depth+1);
        }
    }
    if(!state){
        gae+=depth;
        return;
    }
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n,a,b;
    cin>>n;
    v.resize(n+1,vector<int>());
    for(int i=0;i<n-1;++i){
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1,0);
    if(gae&(1<<0)) cout<<"Yes";
    else cout<<"No";
}