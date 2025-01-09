#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define ll long long
using namespace std;
int dy[4]={1,-1,0,0};
int dx[4]={0,0,1,-1};
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n,m;
    cin>>n>>m;
    vector<vector<int>> v(n,vector<int>(m));
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin>>v[i][j];
        }
    }
    int time=0,cheeze=0;
    while(true){
        bool state=false;
        int tmpCheeze=0;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(v[i][j]==1){
                    state=true;
                    ++tmpCheeze;
                }
            }
        }
        if(!state) break;
        else cheeze=tmpCheeze;
        ++time;
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        visited[0][0]=true;
        queue<pair<int,int>> q;
        q.push({0,0});
        while(!q.empty()){
            int crnY=q.front().first;
            int crnX=q.front().second;
            q.pop();
            for(int i=0;i<4;++i){
                int ny=dy[i]+crnY;
                int nx=dx[i]+crnX;
                if(ny<0||ny>=n||nx<0||nx>=m) continue;
                if(visited[ny][nx]) continue;
                visited[ny][nx]=true;
                if(v[ny][nx]==1){
                    v[ny][nx]=0;
                }
                else q.push({ny,nx});
            }
        }
    }
    cout<<time<<'\n'<<cheeze;
}