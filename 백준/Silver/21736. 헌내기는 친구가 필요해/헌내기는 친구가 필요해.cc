#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int dy[4]={1,-1,0,0};
int dx[4]={0,0,1,-1};
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n,m;
	cin>>n>>m;
	vector<vector<char>> v(n,vector<char>(m));
	vector<vector<bool>> visited(n,vector<bool>(m,false));
	pair<int,int> startNode;
	for(int i=0;i<n;++i){
		string a;
		cin>>a;
		for(int j=0;j<m;++j){
			v[i][j]=a[j];
			if(a[j]=='I'){
				startNode={i,j};
			}
		}
	}
	queue<pair<int,int>> q;
	q.push(startNode);
	visited[startNode.first][startNode.second]=true;
	int ans=0;
	while(!q.empty()){
		int crnY=q.front().first;
		int crnX=q.front().second;
		q.pop();
		for(int i=0;i<4;++i){
			int ny=crnY+dy[i];
			int nx=crnX+dx[i];
			if(ny<0||ny>=n||nx<0||nx>=m) continue;
			if(v[ny][nx]=='X') continue;
			if(visited[ny][nx]) continue;
			visited[ny][nx]=true;
			if(v[ny][nx]=='P') ++ans;
			q.push({ny,nx});
		}
	}
	if(ans==0) cout<<"TT";
	else cout<<ans;
}