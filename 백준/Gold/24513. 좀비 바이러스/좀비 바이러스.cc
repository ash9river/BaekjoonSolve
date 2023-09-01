#include <iostream>
#include <tuple>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector<pair<int,int>> oneVirus;
vector<pair<int,int>> twoVirus;
int n,m;
int board[1000][1000];
int visited[1000][1000];

int dy[4]={1,-1,0,0};
int dx[4]={0,0,1,-1};
bool set(int y,int x,int typeOfVirus){
    if(y<0||y>=n||x<0||x>=m) return false;
    if(board[y][x]==3||board[y][x]==-1) return false;
    if(board[y][x]==typeOfVirus) return false;
    return true;
}
void bfs(){
    queue<pair<tuple<int,int,int>,int>> q;
    int oSize=oneVirus.size(),wSize=twoVirus.size();
    for(int i=0;i<oSize;++i) q.push({{oneVirus[i].first,oneVirus[i].second,1},1});
    for(int i=0;i<wSize;++i) q.push({{twoVirus[i].first,twoVirus[i].second,2},1});
    while(!q.empty()){
        int y=get<0>(q.front().first);
        int x=get<1>(q.front().first);
        int typeOfVirus=get<2>(q.front().first);
        int time=q.front().second;
        q.pop();
        if(board[y][x]==3) continue;
        for(int i=0;i<4;++i){
            int ny=y+dy[i];
            int nx=x+dx[i];
            if(set(ny,nx,typeOfVirus)){
                if(board[ny][nx]==abs(3-typeOfVirus)){
                    if(visited[ny][nx]==time) board[ny][nx]=3;
                    continue;
                }
                board[ny][nx]=typeOfVirus;
                visited[ny][nx]=time;
                q.push({{ny,nx,typeOfVirus},time+1});
            }
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
            if(board[i][j]==1) oneVirus.push_back({i,j});
            else if(board[i][j]==2) twoVirus.push_back({i,j});
        }
    }
    bfs();
    int one=0,two=0,three=0;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(board[i][j]==1) ++one;
            else if(board[i][j]==2) ++two;
            else if(board[i][j]==3) ++three;
        }
    }
    cout<<one<<" "<<two<<" "<<three;
}