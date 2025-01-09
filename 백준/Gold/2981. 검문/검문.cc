#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n;
	cin>>n;
	vector<ll> v(n);
    for(int i=0;i<n;++i){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    vector<ll> vv(n-1);
    for(int i=0;i<n-1;++i){
        vv[i]=v[i+1]-v[i];
    }
    ll a=__gcd(vv[0],vv[1]);
    for(int i=2;i<n-1;++i){
        a=__gcd(a,vv[i]);
    }
    vector<ll> ans;
    for(ll i=1;i*i<=a;++i){
        if(a%i==0){
            ans.push_back(i);
            if(i!=a/i) ans.push_back(a/i);
        }
    }

    sort(ans.begin(),ans.end());
    for(int i=1;i<ans.size();++i){
        cout<<ans[i]<<" ";
    }
}