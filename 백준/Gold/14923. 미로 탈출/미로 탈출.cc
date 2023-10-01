#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int board[1001][1001];
int cache[1001][1001][2];
int n,m;
pair<int,int> startPoint;
pair<int,int> endPoint;
int minTime=987654321;
int dy[4]={1,-1,0,0};
int dx[4]={0,0,1,-1};
bool set(int ny,int nx){
    if(ny<=0||ny>n||nx<=0||nx>m) return false;
    return true;
}
void bfs(){
    queue<pair<pair<int,bool>,pair<int,int>>> q;//time,byeok,y,x
    q.push({{0,false},{startPoint.first,startPoint.second}});
    cache[startPoint.first][startPoint.second][0]=0;
    while(!q.empty()){
        int time=q.front().first.first;
        bool state=q.front().first.second;
        int y=q.front().second.first;
        int x=q.front().second.second;
        q.pop();
        for(int i=0;i<4;++i){
            int ny=dy[i]+y;
            int nx=dx[i]+x;
            if(ny==endPoint.first&&nx==endPoint.second){
                if(board[ny][nx]==1&&state) continue;
                minTime=min(minTime,time+1);
                continue;
            }
            if(set(ny,nx)){
                if(board[ny][nx]==1){
                    if(state) continue;
                    else{
                        if(cache[ny][nx][1]>time+1){
                            cache[ny][nx][1]=time+1;
                            q.push({{time+1,true},{ny,nx}});
                        }
                        else continue;
                    } 
                }
                else{
                    int a=0;
                    if(state){
                        a=1;
                    }
                    if(cache[ny][nx][a]>time+1){
                        cache[ny][nx][a]=time+1;
                        q.push({{time+1,state},{ny,nx}});
                    }
                }
            }
        }
    }
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    cin>>startPoint.first>>startPoint.second;
    cin>>endPoint.first>>endPoint.second;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            cin>>board[i][j];
            for(int k=0;k<2;++k){
                cache[i][j][k]=987654321;
            }
        }
    }
    bfs();
    if(minTime==987654321) minTime=-1;
    cout<<minTime;
}