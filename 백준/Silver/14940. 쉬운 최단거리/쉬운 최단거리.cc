#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int dy[4]={1,-1,0,0};
int dx[4]={0,0,1,-1};
vector<vector<int>> graph(1000,vector<int>(1000));
vector<vector<bool>> visited(1000,vector<bool>(1000,false));
int n,m;
bool set(int y,int x){
    if(y<0||y>=n||x<0||x>=m) return false;
    if(graph[y][x]!=1) return false;
    if(visited[y][x]) return false;
    return true;
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    pair<int,int> start;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin>>graph[i][j];
            if(graph[i][j]==2) start={i,j};
        }
    }
    vector<vector<int>> ans(n,vector<int>(m,987654321));
    queue<pair<int,pair<int,int>>> q;
    q.push({0,{start.first,start.second}});
    visited[start.first][start.second]=true;
    ans[start.first][start.second]=0;
    while(!q.empty()){
        int cost=q.front().first;
        int y=q.front().second.first;
        int x=q.front().second.second;
        q.pop();
        for(int i=0;i<4;++i){
            int ny=y+dy[i];
            int nx=x+dx[i];
            if(set(ny,nx)){
                visited[ny][nx]=true;
                q.push({cost+1,{ny,nx}});
                ans[ny][nx]=cost+1;
            }
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(ans[i][j]==987654321){
                if(graph[i][j]==0) cout<<"0 ";
                else cout<<"-1 ";
            }
            else cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }
}