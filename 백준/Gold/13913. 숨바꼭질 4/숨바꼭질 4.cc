#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int val[100001];
int choice[100001];
int n,k;
void bfs(){
	fill(&val[0],&val[100001],987654321);
	queue<pair<int,int>> q;
	q.push({0,n});
	val[n]=0;
	while(!q.empty()){
		int crnCost=q.front().first;
		int now=q.front().second;
		q.pop();
		int nxt;
		if(now-1>=0){
			nxt=now-1;
			if(val[nxt]>crnCost+1){
				val[nxt]=crnCost+1;
				choice[nxt]=now;
				q.push({crnCost+1,nxt});
			}
		}
		if(now+1<=100000){
			nxt=now+1;
			if(val[nxt]>crnCost+1){
				val[nxt]=crnCost+1;
				choice[nxt]=now;
				q.push({crnCost+1,nxt});
			}
		}
		if(now*2<=100000){
			nxt=now*2;
			if(val[nxt]>crnCost+1){
				val[nxt]=crnCost+1;
				choice[nxt]=now;
				q.push({crnCost+1,nxt});
			}
		}
	}
	cout<<val[k]<<"\n";
	vector<int> ans;
	int p=choice[k];
	ans.push_back(k);
	bool state=true;
	if(n==k) state=false;
	while(state){
		ans.push_back(p);
		if(p==n) break;
		p=choice[p];
	}
	for(int i=ans.size()-1;i>=0;--i){
		cout<<ans[i]<<" ";
	}
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin>>n>>k;
	bfs();
}