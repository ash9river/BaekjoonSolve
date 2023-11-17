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
	int a,b;
	priority_queue<int> input;
	priority_queue<int> output;
	for(int i=0;i<n;++i){
		cin>>a>>b;
		input.push(-a);
		output.push(-b);
	}
	int gae=0;
	int maxGae=0;
	while(!input.empty()){
		int a=-input.top();
		int b=-output.top();
		++gae;
		input.pop();
		if(a>=b){
			--gae;
			output.pop();
		}
		maxGae=max(maxGae,gae);
	}
	cout<<maxGae;

}