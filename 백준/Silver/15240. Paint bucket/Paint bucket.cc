#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int r,c,color,startColor;
pair<int,int> start;
int board[1000][1000];
bool visited[1000][1000];
int dy[4]={-1,1,0,0};
int dx[4]={0,0,1,-1};
bool set(int y,int x){
    if(y<0||y>=r||x<0||x>=c) return false;
    if(visited[y][x]) return false;
    if(board[y][x]!=startColor) return false;
    return true;
}
void bfs(){
    queue<pair<int,int>> q;
    q.push({start.first,start.second});
    visited[start.first][start.second]=true;
    startColor=board[start.first][start.second];
    board[start.first][start.second]=color;
    while(!q.empty()){
        int y=q.front().first;
        int x=q.front().second;
        q.pop();
        for(int i=0;i<4;++i){
            int ny=y+dy[i];
            int nx=x+dx[i];
            if(set(ny,nx)){
                board[ny][nx]=color;
                visited[ny][nx]=true;
                q.push({ny,nx});
            }
        }
    }
    for(int i=0;i<r;++i){
        for(int j=0;j<c;++j){
            cout<<board[i][j];
        }
        cout<<"\n";
    }
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>r>>c;
    for(int i=0;i<r;++i){
        string a;
        cin>>a;
        for(int j=0;j<c;++j){
            board[i][j]=a[j]-'0';
        }
    }
    cin>>start.first>>start.second>>color;
    bfs();
}
