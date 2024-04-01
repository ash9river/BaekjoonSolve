#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector<vector<int>> v(200,vector<int>(200));
vector<vector<int>> cache(200,vector<int>(200));
int dy[4]={1,-1,0,0};
int dx[4]={0,0,1,-1};
int n,k;
bool set(int y,int x){
    if(y<0||y>=n||x<0||x>=n) return false;
    if(v[y][x]!=0) return false;
    return true;
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    // second, type, y, x
    priority_queue<pair<pair<int,int>,pair<int,int>>> q;
    cin>>n>>k;
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            cin>>v[i][j];
            if(v[i][j]!=0){
                q.push({{0,-v[i][j]},{i,j}});
            }
        }
    }
    int s,y,x;
    cin>>s>>y>>x;
    while(!q.empty()){
        int second=-q.top().first.first;
        int type=-q.top().first.second;
        int crnY=q.top().second.first;
        int crnX=q.top().second.second;
        q.pop();
        for(int i=0;i<4;++i){
            int ny=crnY+dy[i];
            int nx=crnX+dx[i];
            if(set(ny,nx)){
                v[ny][nx]=type;
                cache[ny][nx]=second+1;
                q.push({{-(second+1),-type},{ny,nx}});
            }
        }
    }
    --y;
    --x;
    if(v[y][x]==0||cache[y][x]>s) cout<<0;
    else cout<<v[y][x];
}