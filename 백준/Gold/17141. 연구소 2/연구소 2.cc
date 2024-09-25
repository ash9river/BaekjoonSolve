#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <algorithm>
using namespace std;
vector<pair<int,int>> vir;
vector<int> picker;
vector<vector<int>> v;
int n,m,ans=987654321;
int dy[4]={1,-1,0,0};
int dx[4]={0,0,1,-1};

bool set(int y,int x,vector<vector<bool>>& visited){
    if(y<0||y>=n||x<0||x>=n) return false;
    if(v[y][x]==1) return false;
    if(visited[y][x]) return false;
    return true;
}

void infection(){
    queue<tuple<int,int,int>> q;
    vector<vector<bool>> visited(n,vector<bool>(n,false));
    for(int i=0;i<picker.size();++i){
        q.push({0,vir[picker[i]].first,vir[picker[i]].second});
        visited[vir[picker[i]].first][vir[picker[i]].second]=true;
    }
    int maxTime=0;
    while(!q.empty()){
        int crnTime=get<0>(q.front());
        int crnY=get<1>(q.front());
        int crnX=get<2>(q.front());
        q.pop();
        maxTime=max(maxTime,crnTime);
        for(int i=0;i<4;++i){
            int ny=crnY+dy[i];
            int nx=crnX+dx[i];
            if(set(ny,nx,visited)){
                visited[ny][nx]=true;
                q.push({crnTime+1,ny,nx});
            }
        }
    }
    bool state=true;
    for(int i=0;i<n;++i){
        if(!state) break;
        for(int j=0;j<n;++j){
            if(!visited[i][j]){
                if(v[i][j]!=1){
                    state=false;
                    break;
                }
            }
        }
    }
    if(state){
        ans=min(ans,maxTime);
    }
}

void pick(int toPick){
    if(toPick==0){
        infection();
        return;
    }
    int index=picker.empty()?0:picker.back()+1;
    for(int i=index;i<vir.size();++i){
        picker.push_back(i);
        pick(toPick-1);
        picker.pop_back();
    }
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    v.resize(n,vector<int>(n));
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            cin>>v[i][j];
            if(v[i][j]==2){
                vir.push_back({i,j});
            }
        }
    }
    if(vir.size()<m) m=vir.size();
    pick(m);
    if(ans==987654321) ans=-1;
    cout<<ans;
}