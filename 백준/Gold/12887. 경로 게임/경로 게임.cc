#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;
char board[2][50];
int visited[2][50];
int m;
int dy[4]={1,-1,0,0};
int dx[4]={0,0,1,-1};
bool set(int y,int x,int cost){
	if(y<0||y>=2||x<0||x>=m) return false;
	if(board[y][x]=='#') return false;
	if(visited[y][x]<=cost) return false;
	return true;
}
int bfs(){
	fill(&visited[0][0],&visited[1][50],987654321);
	queue<tuple<int,int,int>> q;
	if(board[0][0]=='.') {
		q.push({1,0,0});
		visited[0][0]=1;
	}
	if(board[1][0]=='.') {
		q.push({1,1,0});
		visited[1][0]=1;
	}
	while(!q.empty()){
		int gae=get<0>(q.front());
		int y=get<1>(q.front());
		int x=get<2>(q.front());
		q.pop();
		for(int i=0;i<4;++i){
			int ny=y+dy[i];
			int nx=x+dx[i];
			int nxtCost=gae+1;
			if(set(ny,nx,nxtCost)){
				visited[ny][nx]=nxtCost;
				q.push({nxtCost,ny,nx});
			}
		}
	}
	return min(visited[0][m-1],visited[1][m-1]);
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin>>m;
	int gaeOfBlack=0;
	for(int i=0;i<2;++i){
		string a;
		cin>>a;
		for(int j=0;j<m;++j){
			board[i][j]=a[j];
			if(board[i][j]=='#') ++gaeOfBlack;
		}
	}
	cout<<2*m-bfs()-gaeOfBlack;
}