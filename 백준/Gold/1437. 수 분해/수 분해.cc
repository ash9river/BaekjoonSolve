#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define mod 10007
using namespace std;
int dp[1000001];
int n;
long long maxBun(int val){
	if(val<5) return val;
	int& ret=dp[val];
	if(ret!=-1) return ret;
	if(val%2==0) return ret=(maxBun(val/2)%mod*maxBun(val/2)%mod)%mod;
	return ret=(maxBun((val+1)/2)%mod*maxBun(val/2)%mod)%mod;
}
int gae(int a){
	if(a==1) return 3;
	else if(a==2) return 9;
	int& ret=dp[a];
	if(ret!=-1) return ret;
	if(a%2==0) return ret=((gae(a/2)%mod)*(gae(a/2)%mod))%mod;
	return ret=((gae(a/2)%mod*gae((a+1)/2)%mod))%mod;
}
void init(){
	if(n<5) cout<<n;
	else if(n==5) cout<<6;
	else if(n==6) cout<<9;
	else if(n==7) cout<<12;
	else if(n==8) cout<<18;
	else if(n==9) cout<<27;
	else{
		int countThree=n%3;
		if(countThree==0){
			cout<<gae(n/3);
		}
		else if(countThree==1){
			cout<<((gae((n-4)/3)*4)%mod);
		}
		else{
			cout<<((gae((n-2)/3)*2)%mod);
		}
	}
}


int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	memset(dp,-1,sizeof(dp));
	cin>>n;
	init();
}