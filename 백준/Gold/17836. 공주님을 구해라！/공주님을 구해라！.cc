#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define ll long long
using namespace std;
int board[100][100];
int cache[2][100][100];
int dy[4]={1,-1,0,0};
int dx[4]={0,0,1,-1};
int n,m,t;
bool set(bool state,int time,int y,int x){
    if(y<0||y>=n||x<0||x>=m) return false;
    if(!state&&board[y][x]==1) return false;
    if(cache[state][y][x]<=time) return false;
    return true;
}
int bfs(){
    fill(&cache[0][0][0],&cache[1][99][100],987654321);
    queue<pair<pair<bool,int>,pair<int,int>>> q;//state, time, y, x
    if(board[0][0]==2) q.push({{true,0},{0,0}});
    else q.push({{false,0},{0,0}});
    while(!q.empty()){
        bool state=q.front().first.first;
        int time=q.front().first.second;
        int y=q.front().second.first;
        int x=q.front().second.second;
        q.pop();
        for(int i=0;i<4;++i){
            int ny=dy[i]+y;
            int nx=dx[i]+x;
            int nxtTime=time+1;
            if(set(state,nxtTime,ny,nx)){
                if(board[ny][nx]==2){
                    q.push({{true,nxtTime},{ny,nx}});
                    cache[true][ny][nx]=nxtTime;
                }
                else{
                    q.push({{state,nxtTime},{ny,nx}});
                    cache[state][ny][nx]=nxtTime;
                }
            }
        }
    }
    int ret=min(cache[0][n-1][m-1],cache[1][n-1][m-1]);
    if(ret>t||ret==987654321) return -1;
    return ret;
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>n>>m>>t;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin>>board[i][j];
        }
    }
    int ans=bfs();
    if(ans==-1) cout<<"Fail";
    else cout<<ans;
}