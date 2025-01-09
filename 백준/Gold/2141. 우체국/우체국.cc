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
	vector<pair<ll,ll>> v(n);
    ll p=0;
	for(int i=0;i<n;++i){
		cin>>v[i].first>>v[i].second;
        p+=v[i].second;
	}
	sort(v.begin(),v.end());
    ll gae=0;
    for(int i=0;i<n;++i){
        gae+=v[i].second;
        if(gae*2>=p){
            cout<<v[i].first;
            break;
        }
    }
}