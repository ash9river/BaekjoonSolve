#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int cache[10000][2];
vector<int> v(10000);
int dp[10001];
int n;
/* int pathMax(int now,int pass){
	if(now>=n) return 0;
	int& ret=cache[now][pass];
	if(ret!=-1) return ret;
	if(pass==2){
		return ret=pathMax(now+1,0);
	}
	else{
		return ret=max(v[now]+pathMax(now+1,pass+1),pathMax(now+1,0));
	}
} */
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>v[i];
	}
	if(n==1){
		cout<<v[0];
		return 0;
	}
	else if(n==2){
		cout<<v[0]+v[1];
		return 0;
	}
	else{
		dp[0]=v[0];
		dp[1]=v[0]+v[1];
		dp[2]=v[0]+v[1]+v[2]-min({v[0],v[1],v[2]});
		for(int i=3;i<n;++i){
			dp[i]=max(dp[i-1],max(dp[i-2],dp[i-3]+v[i-1])+v[i]);
		}
		cout<<dp[n-1];
	}
}