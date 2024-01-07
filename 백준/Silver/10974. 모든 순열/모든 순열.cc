#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;
deque<int> picker;
vector<bool> visited(9);
int n;
void pick(int toPick){
	if(toPick==0){
		for(int i=0;i<picker.size()-1;++i){
			cout<<picker[i]<<" ";
		}
		cout<<picker[picker.size()-1]<<'\n';
		return;
	}
	for(int i=1;i<=n;++i){
		if(!visited[i]){
			visited[i]=true;
			picker.push_back(i);
			pick(toPick-1);
			picker.pop_back();
			visited[i]=false;
		}
	}
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin>>n;
	pick(n);
}	