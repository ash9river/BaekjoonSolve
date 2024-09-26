#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector<int> picker;
vector<vector<int>> v;
vector<pair<int,int>> canMakeByeok;
vector<pair<int,int>> vir;
int n,m,ans;
int dy[4]={1,-1,0,0};
int dx[4]={0,0,1,-1};
bool set(int y,int x,vector<vector<int>>& table){
	if(y<0||y>=n||x<0||x>=m) return false;
	if(table[y][x]!=0) return false;
	return true;
}

void bfs(){
	vector<vector<int>> tmpV=v;
	for(int i=0;i<3;++i){
		tmpV[canMakeByeok[picker[i]].first][canMakeByeok[picker[i]].second]=1;
	}
	queue<pair<int,int>> q;
	for(int i=0;i<vir.size();++i){
		q.push({vir[i].first,vir[i].second});
	}
	while(!q.empty()){
		int crnY=q.front().first;
		int crnX=q.front().second;
		q.pop();
		for(int i=0;i<4;++i){
			int ny=crnY+dy[i];
			int nx=crnX+dx[i];
			if(set(ny,nx,tmpV)){
				tmpV[ny][nx]=2;
				q.push({ny,nx});
			}
		}
	}
	int tmpAns=0;
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			if(tmpV[i][j]==0) ++tmpAns;
		}
	}
	ans=max(ans,tmpAns);
}
void pick(int toPick){
	if(toPick==0){
		bfs();
		return;
	}
	int index=picker.empty()?0:picker.back()+1;
	for(int i=index;i<canMakeByeok.size();++i){
		picker.push_back(i);
		pick(toPick-1);
		picker.pop_back();
	}
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin>>n>>m;
	v.resize(n,vector<int>(m));
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			cin>>v[i][j];
			if(v[i][j]==0){
				canMakeByeok.push_back({i,j});
			}
			else if(v[i][j]==2){
				vir.push_back({i,j});
			}
		}
	}
	pick(3);
	cout<<ans;
}