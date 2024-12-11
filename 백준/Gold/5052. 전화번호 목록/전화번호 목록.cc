#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int t;
	cin>>t;
	while(t-->0){
		int n;
		cin>>n;
		map<string,int> m;
		bool state=false;
		vector<string> str(n);
		for(int i=0;i<n;++i){
			cin>>str[i];
		}
		sort(str.begin(),str.end());
		for(int i=0;i<n;++i){
			string tmp="";
			for(int j=0;j<str[i].size();++j){
				tmp+=str[i][j];
				if(m.count(tmp)>0){
					state=true;
					break;
				}
			}
			m.insert({str[i],1});
			if(state) break;
		}
		if(state) cout<<"NO\n";
		else cout<<"YES\n";
	}
}