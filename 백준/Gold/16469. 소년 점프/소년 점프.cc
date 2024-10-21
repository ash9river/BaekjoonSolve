#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int r,c;
int board[100][100];
int visited[3][100][100];
int dy[4]={0,0,1,-1};
int dx[4]={1,-1,0,0};
bool set(int index,int y,int x,int val){
	if(y<0||y>=r||x<0||x>=c) return false;
	if(board[y][x]==1) return false;
	if(visited[index][y][x]<=val) return false;
	return true;
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	fill(&visited[0][0][0],&visited[2][99][100],987654321);
	cin>>r>>c;
	for(int i=0;i<r;++i){
		string str;
		cin>>str;
		for(int j=0;j<c;++j){
			board[i][j]=str[j]-'0';
		}
	}
	vector<pair<int,int>> v(3);
	for(int i=0;i<3;++i){
		cin>>v[i].first>>v[i].second;
		--v[i].first;
		--v[i].second;
		visited[i][v[i].first][v[i].second]=0;
	}
	for(int k=0;k<3;++k){
		priority_queue<pair<int,pair<int,int>>> q;
		q.push({0,{v[k].first,v[k].second}});
		while(!q.empty()){
			int crnTime=-q.top().first;
			int crnY=q.top().second.first;
			int crnX=q.top().second.second;
			q.pop();
			for(int i=0;i<4;++i){
				int ny=crnY+dy[i];
				int nx=crnX+dx[i];
				int nxtTime=crnTime+1;
				if(set(k,ny,nx,nxtTime)){
					visited[k][ny][nx]=nxtTime;
					q.push({-nxtTime,{ny,nx}});
				}
			}
		}
	}
	int ans=987654321;
	for(int i=0;i<r;++i){
		for(int j=0;j<c;++j){
			if(board[i][j]==1) continue;
			bool state=false;
			for(int k=0;k<3;k++){
				if(visited[k][i][j]==987654321) state=true;
			}
			if(state) continue;
			int tmpAns=max({visited[0][i][j],visited[1][i][j],visited[2][i][j]});
			ans=min(ans,tmpAns);
		}
	}
	if(ans==987654321){
		cout<<-1;
	}
	else{
		int gae=0;
		for(int i=0;i<r;++i){
			for(int j=0;j<c;++j){
				if(board[i][j]==1) continue;
				bool state=false;
				for(int k=0;k<3;k++){
					if(visited[k][i][j]==987654321) state=true;
				}
				if(state) continue;
				int tmpGae=max({visited[0][i][j],visited[1][i][j],visited[2][i][j]});
				if(ans==tmpGae) ++gae;
			}
		}
		cout<<ans<<"\n"<<gae;
	}
}