#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int r,c;
char board[250][250];
bool visited[250][250];
pair<int,int> animal={0,0};//yang neuk
int dy[4]={1,-1,0,0};
int dx[4]={0,0,1,-1};
bool set(int y,int x){
    if(y<0||y>=r||x<0||x>=c) return false;
    if(visited[y][x]) return false;
    if(board[y][x]=='#') return false;
    return true;
}
pair<int,int> dfs(int y,int x){
    visited[y][x]=true;
    pair<int,int> tmp={0,0};
    if(board[y][x]=='k') tmp.first=1;
    else if(board[y][x]=='v') tmp.second=1;
    pair<int,int> tmp2;
    for(int i=0;i<4;++i){
        int ny=y+dy[i];
        int nx=x+dx[i];
        for(int i=0;i<4;++i){
            if(set(ny,nx)){
                tmp2=dfs(ny,nx);
                tmp.first+=tmp2.first;
                tmp.second+=tmp2.second;
            }
        }
    }
    return tmp;
}
void init(){
    pair<int,int> tmp;
    for(int i=0;i<r;++i){
        for(int j=0;j<c;++j){
            if(!visited[i][j]&&board[i][j]!='#'){
                tmp=dfs(i,j);
                if(tmp.first>tmp.second){
                    animal.second-=tmp.second;
                }
                else animal.first-=tmp.first;
            }
        }
    }
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>r>>c;
    for(int i=0;i<r;++i){
        for(int j=0;j<c;++j){
            cin>>board[i][j];
            if(board[i][j]=='k') ++animal.first;
            else if(board[i][j]=='v') ++animal.second;
        }
    }
    init();
    cout<<animal.first<<" "<<animal.second;
}