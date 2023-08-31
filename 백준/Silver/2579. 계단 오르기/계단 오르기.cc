#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int stair[300];
int cache[302][2];
int n;
int pathMax(int dan,int pass){
	if(dan<0) return 0;
	int& ret=cache[dan][pass];
	if(ret!=-1) return ret;
	if(pass==0){
		return ret=stair[dan]+pathMax(dan-1,1);
	}
	else{
		return ret=max(stair[dan]+pathMax(dan-2,0),pathMax(dan-1,0));
	}
}

int pathInit(){
	return pathMax(n-1,0);
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin>>n;
	for(int i=0;i<n;++i) cin>>stair[i];
	memset(cache,-1,sizeof(cache));
	cout<<pathInit();
}