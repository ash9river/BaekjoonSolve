#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n;
	cin>>n;
	vector<int> table(n+1);
	priority_queue<pair<int,int>> q;
	for(int i=1;i<=n;++i){
		cin>>table[i];
		q.push({-table[i],-i});
	}
	int m,a,b,c;
	cin>>m;
	for(int i=0;i<m;++i){
		cin>>a;
		if(a==1){
			cin>>b>>c;
			table[b]=c;
			q.push({-c,-b});
		}
		else{
			bool state=true;
			while(state){
				int val=-q.top().first;
				int idx=-q.top().second;
				if(table[idx]!=val) q.pop();
				else{
					cout<<idx<<"\n";
					state=false;
				}
			}
		}
	}
}