#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
bool cmp(pair<int,string> v1,pair<int,string> v2){
	if(v1.first>v2.first) return v1.first>v2.first;
	else if(v1.first<v2.first) return v1.first>v2.first;
	else{
		return v1.second<v2.second;
	}
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n;
	cin>>n;
	vector<pair<int,string>> v(n,pair<int,string>({0,"a"}));
	for(int i=0;i<n;++i) cin>>v[i].second;
	string a;
	while(true){
		cin>>a;
		if(cin.eof()==true) break;
		for(int i=0;i<n;++i){
			if(a==v[i].second){
				++v[i].first;
				break;
			}
		}
	}
	sort(v.begin(),v.end(),cmp);
	for(int i=0;i<n;++i){
		cout<<v[i].second<<" "<<v[i].first<<"\n";
	}
}