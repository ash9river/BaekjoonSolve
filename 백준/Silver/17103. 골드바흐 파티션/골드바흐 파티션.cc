#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
bool prime[1000001];
int gae[1000001];

void makePrime(){
	memset(prime,true,sizeof(prime));
	prime[0]=prime[1]=false;
	for(int i=2;i*i<=1000000;++i){
		if(prime[i]){
			for(int j=i*i;j<=1000000;j+=i){
				prime[j]=false;
			}
		}
	}
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int t;
	cin>>t;
	makePrime();
	for(int i=2;i<=1000000;++i){
	}
	while(t-->0){
		int n;
		cin>>n;
		if(gae[n]==0){
			for(int j=n/2;j>0;--j){
				if(prime[j]&&prime[n-j]){
					++gae[n];
				}
			}
		}
		cout<<gae[n]<<"\n";
	}
}