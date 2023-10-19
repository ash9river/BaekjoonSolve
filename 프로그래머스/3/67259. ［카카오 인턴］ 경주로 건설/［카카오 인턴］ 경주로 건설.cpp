#include <string>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
int cache[25][25][4];
int dy[4]={1,-1,0,0};
int dx[4]={0,0,1,-1};
using namespace std;
bool set(vector<vector<int>>& board,int y,int x,int n){
    if(y<0||y>=n||x<0||x>=n) return false;
    if(board[y][x]==1) return false;
    return true;
}
int solution(vector<vector<int>> board) {
    int answer = 0;
    answer=987654321;
    memset(cache,-1,sizeof(cache));
    int n=board.size();
    queue<pair<pair<int,int>,pair<int,int>>> q; //cost,direction,y,x
    q.push({{0,0},{0,0}});
    q.push({{0,2},{0,0}});
    while(!q.empty()){
        int cost=q.front().first.first;
        int direction=q.front().first.second;
        int crnY=q.front().second.first;
        int crnX=q.front().second.second;
        q.pop();
        vector<pair<int,int>> table(3);
        table[0].first=cost+100;
        table[0].second=direction;
        table[1].first=table[2].first=cost+600;
        if(direction<2){
            table[1].second=2;
            table[2].second=3;
        }
        else{
            table[1].second=0;
            table[2].second=1;
        }
        for(int i=0;i<3;++i){
            int ny=crnY+dy[table[i].second];
            int nx=crnX+dx[table[i].second];
            int nxtCost=table[i].first;
            if(set(board,ny,nx,n)){
                if(cache[ny][nx][table[i].second]!=-1){
                    if(cache[ny][nx][table[i].second]<=nxtCost) continue;
                }
                cache[ny][nx][table[i].second]=nxtCost;
                q.push({{nxtCost,table[i].second},{ny,nx}});
            }
        }
    }
    for(int i=0;i<4;++i){
        if(cache[n-1][n-1][i]!=-1){
            answer=min(answer,cache[n-1][n-1][i]);
        }
    }
    return answer;
}