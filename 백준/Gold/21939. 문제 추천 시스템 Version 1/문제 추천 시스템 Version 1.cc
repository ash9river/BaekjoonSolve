#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#define ll long long
using namespace std; // 1%틀
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n;
	multiset<pair<int,int>> m;// 난이도,문제
	map<int,int> table;//문제,난이도
	cin>>n;
	int a,b;
	for(int i=0;i<n;++i){
		cin>>a>>b;
		table.insert({a,b});
		m.insert({b,a});
	}
	int k;
	cin>>k;
	string str;
	while(k-->0){
		cin>>str>>a;
		if(str=="recommend"){
			if(a==1) cout<<m.rbegin()->second<<"\n";
			else cout<<m.begin()->second<<"\n";
		}
		else if(str=="add"){
			cin>>b;
			table.insert({a,b});
			m.insert({b,a});
		}else{
			int tmp=table[a];
			table.erase(a);
			m.erase({tmp,a});
		}
	}
}