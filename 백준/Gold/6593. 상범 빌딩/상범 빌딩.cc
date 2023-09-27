#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
int l,r,c; //z,y,x
tuple<int,int,int> start;
tuple<int,int,int> escape;
bool visited[30][30][30];
char board[30][30][30];
int dy[6]={1,-1,0,0,0,0};
int dx[6]={0,0,1,-1,0,0};
int dz[6]={0,0,0,0,1,-1};
int time=0;
bool set(int z,int y,int x){
    if(z<0||z>=l||y<0||y>=r||x<0||x>=c) return false;
    if(visited[z][y][x]) return false;
    if(board[z][y][x]=='#') return false;
    return true;
}
bool bfs(){
    queue<pair<int,tuple<int,int,int>>> q;
    visited[get<0>(start)][get<1>(start)][get<2>(start)]=true;
    q.push(make_pair(1,make_tuple(get<0>(start),get<1>(start),get<2>(start))));
    int ret=987654321;
    while(!q.empty()){
        int cost=q.front().first;
        int z=get<0>(q.front().second);
        int y=get<1>(q.front().second);
        int x=get<2>(q.front().second);
        q.pop();
        for(int i=0;i<6;++i){
            int nz=z+dz[i];
            int ny=y+dy[i];
            int nx=x+dx[i];
            if(set(nz,ny,nx)){
                visited[nz][ny][nx]=true;
                if(board[nz][ny][nx]=='E') ret=min(ret,cost);
                else{
                    q.push(make_pair(cost+1,make_tuple(nz,ny,nx)));
                }
            }
        }
    }
    if(ret==987654321){
        return false;
    }
    else{
        time=ret;
        return true;
    }
}



int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    while(true){
        cin>>l>>r>>c;
        if(l==0&&r==0&&c==0) break;
        string a;
        for(int i=0;i<l;++i){
            for(int j=0;j<r;++j){
                cin>>a;
                for(int k=0;k<c;++k){
                    board[i][j][k]=a[k];
                    if(a[k]=='S'){
                        get<0>(start)=i;
                        get<1>(start)=j;
                        get<2>(start)=k;
                    }
                    else if(a[k]=='E'){
                        get<0>(escape)=i;
                        get<1>(escape)=j;
                        get<2>(escape)=k;
                    }
                }
            }
        }
        if(bfs()){
            cout<<"Escaped in "<<time<<" minute(s).\n";
        }
        else{
            cout<<"Trapped!\n";
        }
        memset(visited,false,sizeof(visited));
        fill(&board[0][0][0],&board[29][29][29],'#');
    }
}