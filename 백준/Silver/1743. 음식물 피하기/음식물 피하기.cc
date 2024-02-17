#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define ll long long
using namespace std;
int board[100][100];
bool visited[100][100];
int dy[4]={1,-1,0,0};
int dx[4]={0,0,1,-1};
int n,m,k;
bool set(int y,int x){
    if(y<0||y>=n||x<0||x>=m) return false;
    if(board[y][x]==0) return false;
    if(visited[y][x]) return false;
    return true;
}

int dfs(int y,int x){
    int ret=1;
    for(int i=0;i<4;++i){
        int ny=y+dy[i];
        int nx=x+dx[i];
        if(set(ny,nx)){
            visited[ny][nx]=true;
            ret+=dfs(ny,nx);
        }
    }
    return ret;
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>n>>m>>k;
    int a,b;
    for(int i=0;i<k;++i){
        cin>>a>>b;
        board[a-1][b-1]=1;
    }
    int ans=0;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(!visited[i][j]&&board[i][j]==1){
                visited[i][j]=true;
                ans=max(ans,dfs(i,j));
            }
        }
    }
    cout<<ans;
}