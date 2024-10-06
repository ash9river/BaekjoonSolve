#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
vector<vector<ll>> v;
vector<vector<vector<ll>>> memoi;
ll n,b;
vector<vector<ll>> makeCalc(vector<vector<ll>> one,vector<vector<ll>> two){
	vector<vector<ll>> sum(n,vector<ll>(n,0));
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			for(int k=0;k<n;++k){
				sum[i][j]+=one[i][k]*two[k][j];
				sum[i][j]%=1000;
			}
		}
	}
	return sum;
}

vector<vector<ll>> calc(ll b){
	vector<vector<ll>> ret(n,vector<ll>(n,0));
	int ptr=0;
	for(int i=0;i<n;++i){
		ret[i][ptr]=1;
		++ptr;
	}
	for(ll i=63;i>=0;--i){
		if(b&((ll)1<<i)){
			ret=makeCalc(ret,memoi[i]);
		}
	}
	return ret;
} 

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin>>n>>b;
	v.resize(n,vector<ll>(n,0));
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			cin>>v[i][j];
		}
	}
	int ptr=0;
	for(ll i=63;i>=0;--i){
		if(b&((ll)1<<i)){
			ptr=i+1;
			break;
		}
	}
	memoi.resize(ptr+1,vector<vector<ll>>(n,vector<ll>(n,98764321)));
 	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			memoi[0][i][j]=v[i][j];
		}
	}
	for(int k=1;k<ptr;++k){
		memoi[k]=makeCalc(memoi[k-1],memoi[k-1]);
	}
	vector<vector<ll>> ans=calc(b);
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			cout<<ans[i][j]<<" ";
		}
		cout<<"\n";
	}
}