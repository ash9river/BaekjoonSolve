#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n,k;
	cin>>n>>k;
	vector<int> v(n);
	for(int i=0;i<n;++i){
		cin>>v[i];
	}
	sort(v.begin(),v.end());
	vector<int> dp(k+1,987654321);
	for(int i=0;i<n;++i){
		if(v[i]>k) continue;
		dp[v[i]]=1;
		for(int j=2*dp[i];j<=k;j+=dp[i]){
			dp[j]=min(dp[j],dp[j-dp[v[i]]]+1);
		}
	}
	for(int i=0;i<=k;++i){
		for(int j=0;j<=i;++j){
			dp[i]=min(dp[i],dp[i-j]+dp[j]);
		}
	}
	if(dp[k]==987654321) dp[k]=-1;
	cout<<dp[k];
}