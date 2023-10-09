#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
#define ll long long
using namespace std;
char board[1000][1000];
bool visited[1000][1000][10];
pair<int,int> startPoint;
int h,w,n;
int dy[4]={1,-1,0,0};
int dx[4]={0,0,1,-1};
ll minTime=10987654321;
bool set(int y,int x,int dan){
    if(y<0||y>=h||x<0||x>=w) return false;
    if(visited[y][x][dan]) return false;
    if(board[y][x]=='X') return false;
    return true;
}
void bfs(){
    ll times=0;
    queue<pair<pair<ll,int>,pair<int,int>>> q;
    q.push({{0,0},{startPoint.first,startPoint.second}});
    visited[startPoint.first][startPoint.second][0]=true;
    while(!q.empty()){
        ll crnTime=q.front().first.first;
        int crnEatCheese=q.front().first.second;
        int crnY=q.front().second.first;
        int crnX=q.front().second.second;
        q.pop();
        for(int i=0;i<4;++i){
            int ny=crnY+dy[i];
            int nx=crnX+dx[i];
            if(set(ny,nx,crnEatCheese)){
                if(board[ny][nx]>='1'&&board[ny][nx]<='9'){
                    int nxtCheese=board[ny][nx]-'0';
                    if(nxtCheese-crnEatCheese==1){
                        if(nxtCheese==n){
                            minTime=min(minTime,crnTime+(ll)1);
                            continue;
                        }
                        visited[ny][nx][nxtCheese]=true;
                        q.push({{crnTime+(ll)1,nxtCheese},{ny,nx}});
                        continue;
                    }
                }
                visited[ny][nx][crnEatCheese]=true;
                q.push({{crnTime+(ll)1,crnEatCheese},{ny,nx}});
            }
        }
    }
    cout<<minTime;
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>h>>w>>n;
    for(int i=0;i<h;++i){
        string str;
        cin>>str;
        for(int j=0;j<w;++j){
            board[i][j]=str[j];
            if(board[i][j]=='S'){
                startPoint={i,j};
            }
        }
    }
    bfs();
}