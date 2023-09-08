#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector<vector<int>> board;
vector<vector<int>> cache;
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
int n,m;
int cCount;
int minGae=987654321;
vector<pair<int,pair<int,int>>> C;
vector<int> picker;
vector<int> tmp(64);
int ptr;
bool set(int y,int x){
    if(y<0||y>=n||x<0||x>=m) return false;
    if(board[y][x]==6) return false;
    return true;
}
void cal(){
    int sagak=0;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(cache[i][j]==0) ++sagak;
        }
    }
    minGae=min(minGae,sagak);
    return;
}
void pick(int gae){
    if(gae<=0){
        copy(board.begin(),board.end(),cache.begin());
        int ny,nx,ty;
        for(int i=0;i<cCount;++i){
            switch (C[i].first){
            case 1:
                ny=dy[picker[i]]+C[i].second.first;
                nx=dx[picker[i]]+C[i].second.second;
                while(true){
                    if(!set(ny,nx)) break;
                    if(cache[ny][nx]==0) cache[ny][nx]=-1;
                    ny+=dy[picker[i]];
                    nx+=dx[picker[i]];
                }
                break;
            case 2:
                ny=dy[picker[i]]+C[i].second.first;
                nx=dx[picker[i]]+C[i].second.second;
                while(true){
                    if(!set(ny,nx)) break;
                    if(cache[ny][nx]==0) cache[ny][nx]=-1;
                    ny+=dy[picker[i]];
                    nx+=dx[picker[i]];
                }
                ty=(picker[i]+2)%4;
                ny=dy[ty]+C[i].second.first;
                nx=dx[ty]+C[i].second.second;
                while(true){
                    if(!set(ny,nx)) break;
                    if(cache[ny][nx]==0) cache[ny][nx]=-1;
                    ny+=dy[ty];
                    nx+=dx[ty];
                }
                break;
            case 3:
                ny=dy[picker[i]]+C[i].second.first;
                nx=dx[picker[i]]+C[i].second.second;
                while(true){
                    if(!set(ny,nx)) break;
                    if(cache[ny][nx]==0) cache[ny][nx]=-1;
                    ny+=dy[picker[i]];
                    nx+=dx[picker[i]];
                }
                ty=(picker[i]+1)%4;
                ny=dy[ty]+C[i].second.first;
                nx=dx[ty]+C[i].second.second;
                while(true){
                    if(!set(ny,nx)) break;
                    if(cache[ny][nx]==0) cache[ny][nx]=-1;
                    ny+=dy[ty];
                    nx+=dx[ty];
                }
                break;
            case 4:
                ny=dy[picker[i]]+C[i].second.first;
                nx=dx[picker[i]]+C[i].second.second;
                while(true){
                    if(!set(ny,nx)) break;
                    if(cache[ny][nx]==0) cache[ny][nx]=-1;
                    ny+=dy[picker[i]];
                    nx+=dx[picker[i]];
                }
                ty=(picker[i]+1)%4;
                ny=dy[ty]+C[i].second.first;
                nx=dx[ty]+C[i].second.second;
                while(true){
                    if(!set(ny,nx)) break;
                    if(cache[ny][nx]==0) cache[ny][nx]=-1;
                    ny+=dy[ty];
                    nx+=dx[ty];
                }
                ty=(picker[i]+2)%4;
                ny=dy[ty]+C[i].second.first;
                nx=dx[ty]+C[i].second.second;
                while(true){
                    if(!set(ny,nx)) break;
                    if(cache[ny][nx]==0) cache[ny][nx]=-1;
                    ny+=dy[ty];
                    nx+=dx[ty];
                }
                break;
            case 5:
                for(int j=0;j<4;++j){
                    ny=dy[j]+C[i].second.first;
                    nx=dx[j]+C[i].second.second;
                    while(true){
                        if(!set(ny,nx)) break;
                        if(cache[ny][nx]==0) cache[ny][nx]=-1;
                        ny+=dy[j];
                        nx+=dx[j];
                    }
                }
                break;
            }
        }
        cal();
        return;
    }
    int t=ptr;
    for(int i=0;i<4;++i){
        picker[ptr++]=i;
        pick(gae-1);
        --ptr;
    }
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    board.resize(n,vector<int>(m));
    cache.resize(n,vector<int>(m));
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin>>board[i][j];
            if(board[i][j]!=0&&board[i][j]!=6){
                C.push_back({board[i][j],{i,j}});
                ++cCount;
            }
        }
    }
    picker.resize(cCount);
    pick(cCount);
    if(minGae==987654321) minGae=0;
    cout<<minGae;
}