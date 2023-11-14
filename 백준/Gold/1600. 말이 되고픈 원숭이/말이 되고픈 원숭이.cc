#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int board[200][200];
int w,h,k;
int time=987654321;
int cache[401][200][200];
int dy[12]={1,-1,0,0,-1,-2,-2,-1,1,2,2,1};
int dx[12]={0,0,1,-1,-2,-1,1,2,2,1,-1,-2};
bool set(int kGae,int cost,int y,int x){
	if(y<0||y>=h||x<0||x>=w) return false;
	if(board[y][x]==1) return false;
	if(cost>=cache[kGae][y][x]) return false;
	return true;
}
void bfs(){
	queue<pair<pair<int,int>,pair<int,int>>> q;
	fill(&cache[0][0][0],&cache[400][199][200],987654321);
	q.push({{0,0},{0,0}});
	while(!q.empty()){
		int kGae=q.front().first.first;
		int cost=q.front().first.second;
		int y=q.front().second.first;
		int x=q.front().second.second;
		q.pop();
		if(y==h-1&&x==w-1){
			time=min(time,cost);
			continue;
		}
		for(int i=0;i<4;++i){
			int ny=y+dy[i];
			int nx=x+dx[i];
			int nxtCost=cost+1;
			if(set(kGae,nxtCost,ny,nx)){
				q.push({{kGae,nxtCost},{ny,nx}});
				cache[kGae][ny][nx]=nxtCost;
			}
		}
		if(kGae<k){
			for(int i=4;i<12;++i){
				int ny=y+dy[i];
				int nx=x+dx[i];
				int nxtCost=cost+1;
				int nxtGae=kGae+1;
				if(set(nxtGae,nxtCost,ny,nx)){
				q.push({{nxtGae,nxtCost},{ny,nx}});
				cache[nxtGae][ny][nx]=nxtCost;
				}
			}
		}
	}
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin>>k>>w>>h;
	for(int i=0;i<h;++i){
		for(int j=0;j<w;++j){
			cin>>board[i][j];
		}
	}
	bfs();
	if(time==987654321) cout<<-1;
	else cout<<time;
}