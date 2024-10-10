#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;
vector<vector<char>> v;
vector<vector<int>> visited;
int ans=987654321;
int dy[8]={1,1,1,0,0,-1,-1,-1};
int dx[8]={1,0,-1,-1,1,1,0,-1};
int h,w;
bool set(int y,int x,int val){
	if(y<0||y>=h||x<0||x>=w) return false;
	if(v[y][x]=='#') return false;
	if(visited[y][x]<=val) return false;
	return true;
}


int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin>>h>>w;
	v.resize(h,vector<char>(w));
	pair<int,int> startPoint;
	pair<int,int> endPoint;
	for(int i=0;i<h;++i){
		string a;
		cin>>a;
		for(int j=0;j<w;++j){
			v[i][j]=a[j];
			if(a[j]=='K'){
				startPoint={i,j};
			}
			else if(a[j]=='*'){
				endPoint={i,j};
			}
		}
	}
	priority_queue<tuple<int,int,int>> q;
	q.push({0,startPoint.first,startPoint.second});
	visited.resize(h,vector<int>(w,987654321));
	visited[startPoint.first][startPoint.second]=0;
	while(!q.empty()){
		int crnVal=-get<0>(q.top());
		int crnY=get<1>(q.top());
		int crnX=get<2>(q.top());
		q.pop();
		for(int i=0;i<8;++i){
			int ny=crnY+dy[i];
			int nx=crnX+dx[i];
			int nxtVal=crnVal;
			if(dx[i]!=1) ++nxtVal;
			if(set(ny,nx,nxtVal)){
				visited[ny][nx]=nxtVal;
				q.push({-nxtVal,ny,nx});
			}
		}
	}
	ans=visited[endPoint.first][endPoint.second];
	if(ans==987654321) ans=-1;
	cout<<ans;
}