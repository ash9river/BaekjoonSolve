#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;
int board[125][125];
int dy[4]={1,-1,0,0};
int dx[4]={0,0,1,-1};
int n;
bool set(int y,int x){
    if(y<0||y>=n||x<0||x>=n) return false;
    return true;
}
int dijkstra(int startY,int startX){
    vector<vector<int>> dist(n,vector<int>(n,INF));
    dist[startY][startX]=0;
    priority_queue<pair<int,pair<int,int>>> pq;
    pq.push({0,{startY,startX}});
    while(!pq.empty()){
        int cost=-pq.top().first;
        int y=pq.top().second.first;
        int x=pq.top().second.second;
        pq.pop();
        if(dist[y][x]<cost) continue;
        for(int i=0;i<4;++i){
            int ny=y+dy[i];
            int nx=x+dx[i];
            int nxtCost=cost+board[ny][nx];
            if(!set(ny,nx)) continue;
            if(dist[ny][nx]>nxtCost){
                dist[ny][nx]=nxtCost;
                pq.push({-nxtCost,{ny,nx}});
            }
        }
    }
    return dist[n-1][n-1]+board[0][0];
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int ptr=1;
    while(true){
        cin>>n;
        if(n==0) break;
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                cin>>board[i][j];
            }
        }
        cout<<"Problem "<<ptr<<": "<<dijkstra(0,0)<<"\n";
        ++ptr;
    }
}