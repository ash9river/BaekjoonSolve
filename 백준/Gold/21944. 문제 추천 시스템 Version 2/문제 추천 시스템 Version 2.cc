#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std; // 1%틀
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	// recommand 1 : 난이도 번호, 그룹에 따른 set<pair<int,multimap>에서 따로
	// recommand 2 : 난이도, 번호
	// recommand 3 : x=1 lower_bound, x=-1 lower_bound reverse처리
	
	// recommand 1의 탐색
	vector<multiset<pair<int,int>>> v(101,multiset<pair<int,int>>());
	// recommand 2,3의 탐색 난이도, 번호 그룹
	multiset<pair<int,pair<int,int>>> s;
	// 번호 난이도
	map<int,pair<int,int>> table;
	int n;
	cin>>n;
	int a,b,c;
	for(int i=0;i<n;++i){
		cin>>a>>b>>c;//번호 난이도 그룹
		v[c].insert({b,a}); // 그룹 난이도 번호
		s.insert({b,{a,c}}); // 난이도 번호 그룹
		table[a]={b,c}; //번호 난이도 그룹
	}
	int m;
	cin>>m;
	string str;
	while(m-->0){
		cin>>str;
		if(str=="recommend"){
			cin>>a>>b;
			if(b==1) cout<<v[a].rbegin()->second<<"\n";
			else cout<<v[a].begin()->second<<"\n";
		}
		else if(str=="recommend2"){
			cin>>b;
			if(b==1) cout<<s.rbegin()->second.first<<"\n";
			else cout<<s.begin()->second.first<<"\n";
		}
		else if(str=="recommend3"){
			cin>>b>>a;
			if(b==1){
				auto tmp=s.lower_bound({a,{0,0}});
				bool state=false;
				for(auto it=tmp;it!=s.end();++it){
					cout<<it->second.first<<"\n";
					state=true;
					break;
				}
				if(!state) cout<<"-1\n";
			}
			else{
				bool state=false;
				auto it=s.lower_bound({a,{0,0}});
				if(it!=s.begin()){
					--it;
					if(it->first<a){
						cout<<it->second.first<<"\n";
						state=true;
					}
				}
				if(!state) cout<<"-1\n";
			}	
		}
		else if(str=="add"){
			cin>>a>>b>>c;//번호,난이도,그룹
			v[c].insert({b,a});
			s.insert({b,{a,c}});
			table[a]={b,c};
		}
		else{
			cin>>a;
			int tmp=table[a].first;//난이도
			int g=table[a].second;//그룹
			table.erase(a);
			v[g].erase({tmp,a});
			s.erase({tmp,{a,g}});
		}
	}
}