#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n;
	cin>>n;
	vector<string> v(n);
	for(int i=0;i<n;++i){
		cin>>v[i];
	}
	if(n==2){
		if(v[0]>v[1]) cout<<"DECREASING";
		else cout<<"INCREASING";
	}else{
		bool state;
		bool realAns=false;
		if(v[0]>v[1]) state=true;
		else state=false;
		if(state){
			for(int i=1;i<n-1;++i){
				if(v[i]<v[i+1]){
					realAns=true;
					break;
				}
			}
		}else{
			for(int i=1;i<n-1;++i){
				if(v[i]>v[i+1]){
					realAns=true;
					break;
				}
			}
		}
		if(realAns) cout<<"NEITHER";
		else if(state) cout<<"DECREASING";
		else cout<<"INCREASING";
	}
}