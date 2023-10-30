#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;// 10% 틀
vector<int> ans(100001);
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n;
	cin>>n;
	vector<pair<int,int>> table(n);
	for(int i=0;i<n;++i){
		cin>>table[i].first>>table[i].second;
	}
	sort(table.begin(),table.end());
	priority_queue<pair<int,int>> q;
	for(int i=0;i<n;++i){
		q.push({-table[i].first,-table[i].second});
	}
	int ptr=0;
	int maxGae=0;
	priority_queue<pair<int,int>> jariQ;
	priority_queue<int> indexQ;
	while(!q.empty()){
		int P=-q.top().first;
		int Q=-q.top().second;
		q.pop();
		if(jariQ.empty()){
			jariQ.push({-Q,0});
			++ans[0];
		}
		else{
			int jariTime=-jariQ.top().first;
			if(jariTime>P){

				if(indexQ.empty()) ptr=jariQ.size();
				else{
					ptr=-indexQ.top();
					indexQ.pop();
				}
				jariQ.push({-Q,ptr});
				++ans[ptr];
			}
			else{
				while(!jariQ.empty()){
					int tmpTime=-jariQ.top().first;
					if(P>tmpTime){
						indexQ.push(-jariQ.top().second);
						jariQ.pop();
					}
					else break;
				}
				int idx=-indexQ.top();
				indexQ.pop();
				jariQ.push({-Q,idx});
				++ans[idx];
			}
		}
		maxGae=max(maxGae,ptr);
	}
	cout<<maxGae+1<<"\n";
	for(int i=0;i<=maxGae;++i){
		cout<<ans[i]<<" ";
	}
}