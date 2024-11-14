#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define ll long long
using namespace std;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	ll a,b;
	cin>>a>>b;
	vector<bool> v(b+1,true);
	v[0]=v[1]=false;
	for(ll i=2;i<=b;++i){
		if(v[i]){
			for(ll j=i*i;j<=b;j+=i){
				v[j]=false;
			}
		}
	}
	vector<ll> ans;
	for(ll i=a;i<=b;++i){
		if(!v[i]) continue;
		string tmpA=to_string(i);
		string tmpB=tmpA;
		reverse(tmpB.begin(),tmpB.end());
		if(tmpA==tmpB) ans.push_back(i);
	}
	for(int i=0;i<ans.size();++i){
		cout<<ans[i]<<"\n";
	}
	cout<<-1;
}