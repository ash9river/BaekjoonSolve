#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
int board[2000][2000];
int n,m;
int dy[4]={1,-1,0,0};
int dx[4]={0,0,1,-1};
bool visited[2000][2000];
bool check[2000][2000][4];
vector<pair<int,int>> air;
bool set(int y,int x,int type){
    if(y<0||y>=n||x<0||x>=m) return false;
    if(board[y][x]==9) return false;
    if(check[y][x][type]) return false;
    return true;
}
bool set(int y,int x){
    if(y<0||y>=n||x<0||x>=m) return false;
    if(board[y][x]==9) return false;
    return true;
}
int changeTypeTh(int type){
    switch(type){
        case 0:
            return 3;
        case 1:
            return 2;
        case 2:
            return 1;
        default:
            return 0;
    }
}
int changeTypeFo(int type){
    switch(type){
        case 0:
            return 2;
        case 1:
            return 3;
        case 2:
            return 0;
        default:
            return 1;
    }
}
void countJari(){
    queue<pair<int,int>> q;
    for(int i=0;i<air.size();++i){
        q.push({air[i].first,air[i].second});
    }
    while(!q.empty()){
        int y=q.front().first;
        int x=q.front().second;
        q.pop();
        visited[y][x]=true;
        queue<tuple<int,int,int>> jariQ;
        for(int i=0;i<4;++i){
            if(set(y+dy[i],x+dx[i])){
                jariQ.push(make_tuple(i,y,x));
            }
        }
        while(!jariQ.empty()){
            int type=get<0>(jariQ.front());
            int jariY=get<1>(jariQ.front());
            int jariX=get<2>(jariQ.front());
            visited[jariY][jariX]=true;
            jariQ.pop();
            int nextY=jariY+dy[type];
            int nextX=jariX+dx[type];
            if(set(nextY,nextX,type)){
                check[nextY][nextX][type]=true;
                if(board[nextY][nextX]==0){
                    jariQ.push(make_tuple(type,nextY,nextX));
                    continue;
                }
                else if(board[nextY][nextX]==1){
                    if(type==2||type==3){
                        visited[nextY][nextX]=true;
                        continue;
                    }
                }
                else if(board[nextY][nextX]==2){
                    if(type==0||type==1){
                        visited[nextY][nextX]=true;
                        continue;
                    }
                }
                else if(board[nextY][nextX]==3){
                    type=changeTypeTh(type);
                }
                else{
                    type=changeTypeFo(type);
                }
                jariQ.push(make_tuple(type,nextY,nextX));
            }
        }
    }
}
void printGae(){
    int a=0;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(visited[i][j]) ++a;
        }
    }
    cout<<a;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin>>board[i][j];
            if(board[i][j]==9) air.push_back({i,j});
        }
    }
    countJari();
    printGae();
}