#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int board[250][250];
bool visited[250][250];
int gae;
int dy[8]={1,1,1,-1,-1,-1,0,0};
int dx[8]={0,1,-1,0,1,-1,1,-1};
int n,m;
bool set(int y,int x){
    if(y<0||y>=n||x<0||x>=m) return false;
    if(board[y][x]==0) return false;
    if(visited[y][x]) return false;
    return true;
}
void dfs(int y,int x){
    for(int i=0;i<8;++i){
        int ny=y+dy[i];
        int nx=x+dx[i];
        if(set(ny,nx)){
            visited[ny][nx]=true;
            dfs(ny,nx);
        }
    }
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin>>board[i][j];
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(!visited[i][j]&&board[i][j]==1){
                ++gae;
                dfs(i,j);
            }
        }
    }
    cout<<gae;
}