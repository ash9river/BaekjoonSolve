#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int cache[10000][2];
vector<int> v(10000);
int dp[10000];
int n;
int pathMax(int now,int pass){
	if(now>=n) return 0;
	int& ret=cache[now][pass];
	if(ret!=-1) return ret;
	if(pass==2){
		return ret=pathMax(now+1,0);
	}
	else{
		return ret=max(v[now]+pathMax(now+1,pass+1),pathMax(now+1,0));
	}
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>v[i];
	}
	memset(cache,-1,sizeof(cache));
	cout<<pathMax(0,0);
}