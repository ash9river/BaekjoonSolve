#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int board[20][20];
int n;
int ans;
bool set(int y,int x){
	if(y>=n||y<0||x>=n||x<0) return false;
	if(board[y][x]==1) return false;
	return true;
}
void bfs(){
	queue<pair<pair<int,int>,pair<int,int>>> q;
	q.push({{0,0},{0,1}});
	while(!q.empty()){
		int leftY=q.front().first.first;
		int leftX=q.front().first.second;
		int rightY=q.front().second.first;
		int rightX=q.front().second.second;
		q.pop();
		if(rightY==n-1&&rightX==n-1){
			++ans;
			continue;
		}
		if(leftY==rightY){
			if(set(rightY,rightX+1)){
				q.push({{rightY,rightX},{rightY,rightX+1}});
			}
			if(set(rightY+1,rightX)&&set(rightY,rightX+1)&&set(rightY+1,rightX+1)){
				q.push({{rightY,rightX},{rightY+1,rightX+1}});
			}
		}
		else if(leftX==rightX){
			if(set(rightY+1,rightX)){
				q.push({{rightY,rightX},{rightY+1,rightX}});
			}
			if(set(rightY+1,rightX)&&set(rightY,rightX+1)&&set(rightY+1,rightX+1)){
				q.push({{rightY,rightX},{rightY+1,rightX+1}});
			}
		}
		else{
			if(set(rightY,rightX+1)){
				q.push({{rightY,rightX},{rightY,rightX+1}});
			}
			if(set(rightY+1,rightX)){
				q.push({{rightY,rightX},{rightY+1,rightX}});
			}
			if(set(rightY+1,rightX)&&set(rightY,rightX+1)&&set(rightY+1,rightX+1)){
				q.push({{rightY,rightX},{rightY+1,rightX+1}});
			}
		}
	}
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin>>n;
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			cin>>board[i][j];
		}
	}
	bfs();
	cout<<ans;
}