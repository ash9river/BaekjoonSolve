#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define ll long long
using namespace std;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n;
	cin>>n;
	bool state=true;
	priority_queue<pair<int,int>> q;
	int a,b;
	for(int i=0;i<n;++i){
		cin>>a>>b;
		q.push({b,a});
	}
	int crnTime=q.top().first;
	while(!q.empty()){
		int endOfTime=q.top().first;
		int startOfTime=q.top().second;
		q.pop();
		if(crnTime>endOfTime){
			crnTime=endOfTime;
		}
		crnTime-=startOfTime;
		if(crnTime<0){
			state=false;
			break;
		}
	}
	if(!state) cout<<-1;
	else cout<<crnTime;
}