#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;
char board[50][50];
int dy[4]={1,-1,0,0};
int dx[4]={0,0,1,-1};
int cache[50][50][5][5][5][5][5];
vector<pair<int,int>> usan;
pair<int,int> starting;
int n,m;
bool set(int cost,bool a,bool b,bool c,bool d,bool e,int y,int x){
    if(y<0||y>=n||x<0||x>=m) return false;
    if(board[y][x]=='#') return false;
    if(cache[y][x][a][b][c][d][e]<=cost) return false;
    return true;
}
void bfs(){// 칸 ,분실물 5개, 위치
    queue<pair<pair<tuple<int,bool,bool>,tuple<bool,bool,bool>>,pair<int,int>>> q;
    int usanGae=usan.size();
    int ans=987654321;
    fill(&cache[0][0][0][0][0][0][0],&cache[49][49][4][4][4][4][5],987654321);
    cache[0][0][0][0][0][0][0]=0;
    q.push({{{0,false,false},{false,false,false}},{starting.first,starting.second}});
    while(!q.empty()){
        int cost=get<0>(q.front().first.first);
        vector<bool> target(5,false);
        target[0]=get<1>(q.front().first.first);
        target[1]=get<2>(q.front().first.first);
        target[2]=get<0>(q.front().first.second);
        target[3]=get<1>(q.front().first.second);
        target[4]=get<2>(q.front().first.second);
        int nowY=q.front().second.first;
        int nowX=q.front().second.second;
        q.pop();
        for(int i=0;i<4;++i){
            int ny=nowY+dy[i];
            int nx=nowX+dx[i];
            int nxtCost=cost+1;
            if(set(nxtCost,target[0],target[1],target[2],target[3],target[4],ny,nx)){
                if(board[ny][nx]=='E'){
                    bool state=true;
                    for(int i=0;i<usanGae;++i){
                        if(!target[i]){
                            state=false;
                            break;
                        }
                    }
                    if(state){
                        ans=min(ans,cost+1);
                    }
                }
                else if(board[ny][nx]=='X'){
                    int type;
                    for(int i=0;i<usanGae;++i){
                        if(usan[i].first==ny&&usan[i].second==nx){
                            type=i;
                            break;
                        }
                    }
                    if(!target[type]){
                        cache[ny][nx][target[0]][target[1]][target[2]][target[3]][target[4]]=nxtCost;
                        target[type]=true;
                        q.push({{{nxtCost,target[0],target[1]},{target[2],target[3],target[4]}},{ny,nx}});
                        cache[ny][nx][target[0]][target[1]][target[2]][target[3]][target[4]]=nxtCost;
                        target[type]=false;
                    }
                    else{
                        q.push({{{nxtCost,target[0],target[1]},{target[2],target[3],target[4]}},{ny,nx}});
                        cache[ny][nx][target[0]][target[1]][target[2]][target[3]][target[4]]=nxtCost;
                    }
                }else{
                    cache[ny][nx][target[0]][target[1]][target[2]][target[3]][target[4]]=nxtCost;
                    q.push({{{nxtCost,target[0],target[1]},{target[2],target[3],target[4]}},{ny,nx}});
                }
            }
        }
    }
    cout<<ans;
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>m>>n;
    for(int i=0;i<n;++i){
        string a;
        cin>>a;
        for(int j=0;j<m;++j){
            board[i][j]=a[j];
            if(a[j]=='S') starting={i,j};
            else if(a[j]=='X') usan.push_back({i,j});
        }
    }
    bfs();
}