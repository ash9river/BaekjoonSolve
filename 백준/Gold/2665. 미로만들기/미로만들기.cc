#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <tuple>
#include <algorithm>
using namespace std;
int n;
int board[50][50];
int cache[50][50][2501];
int dy[4]={1,-1,0,0};
int dx[4]={0,0,1,-1};
bool set(int y,int x){
    if(y<0||y>=n||x<0||x>=n) return false;
    return true;
}
void bfs(){
    queue<tuple<int,int,int>> q;
    q.push({0,0,0});
    cache[0][0][0]=0;
    while(!q.empty()){
        int gae=get<0>(q.front());
        int y=get<1>(q.front());
        int x=get<2>(q.front());
        q.pop();
        for(int i=0;i<4;++i){
            int ny=y+dy[i];
            int nx=x+dx[i];
            if(set(ny,nx)){
                int nxtGae=gae;
                if(board[ny][nx]==0) ++nxtGae;
                int& ret=cache[ny][nx][nxtGae];
                if(ret!=-1){
                    if(ret<=nxtGae) continue;
                }
                ret=nxtGae;
                q.push({nxtGae,ny,nx});
            }
        }
    }
    int ans=987654321;
    for(int i=0;i<=n*n;++i){
        if(cache[n-1][n-1][i]!=-1){
            ans=min(ans,cache[n-1][n-1][i]);
        }
    }
    cout<<ans;
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=0;i<n;++i){
        string a;
        cin>>a;
        for(int j=0;j<n;++j){
            board[i][j]=a[j]-'0';
        }
    }
    memset(cache,-1,sizeof(cache));
    bfs();
}