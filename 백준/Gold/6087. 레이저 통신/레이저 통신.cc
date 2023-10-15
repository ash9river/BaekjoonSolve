#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
char board[100][100];
int visited[100][100][4];
vector<pair<int,int>> laser;
int w,h;
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};

bool set(int cost,int type,int y,int x){
    if(y<0||y>=h||x<0||x>=w) return false;
    if(board[y][x]=='*') return false;
    if(visited[y][x][type]<=cost) return false;
    return true;
}
int bfs(){
    queue<pair<pair<int,int>,pair<int,int>>> q;
    for(int i=0;i<4;++i){
        q.push({{0,i},{laser[0].first,laser[0].second}});
    }
    while(!q.empty()){
        int costOfMirror=q.front().first.first;
        int direction=q.front().first.second;
        int crnY=q.front().second.first;
        int crnX=q.front().second.second;
        q.pop();
        vector<int> v(3);
        v[0]=direction;
        if(direction==0||direction==2){
            v[1]=1;
            v[2]=3;
        }
        else{
            v[1]=0;
            v[2]=2;
        }
        for(int i=0;i<3;++i){
            int ny=crnY+dy[v[i]];
            int nx=crnX+dx[v[i]];
            int nxtCost=(i==0)?costOfMirror:costOfMirror+1;
            if(set(nxtCost,v[i],ny,nx)){
                visited[ny][nx][v[i]]=nxtCost;
                q.push({{nxtCost,v[i]},{ny,nx}});
            }
        }
    }
    int minGae=visited[laser[1].first][laser[1].second][0];
    for(int i=1;i<4;++i){
        minGae=min(minGae,visited[laser[1].first][laser[1].second][i]);
    }
    return minGae;
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>w>>h;
    for(int i=0;i<h;++i){
        string str;
        cin>>str;
        for(int j=0;j<w;++j){
            board[i][j]=str[j];
            if(board[i][j]=='C') laser.push_back({i,j});
        }
    }
    fill(&visited[0][0][0],&visited[99][99][4],987654321);
    cout<<bfs();
}