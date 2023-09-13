#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n;
	cin>>n;
	vector<int> v(n);
	vector<int> m;
	vector<int> p;
	int zeroCount=0,result=0;
	for(int i=0;i<n;++i){
		cin>>v[i];
		if(v[i]<0) m.push_back(v[i]);
		else if(v[i]==0) ++zeroCount;
		else p.push_back(v[i]);
	}
	sort(m.begin(),m.end());
	sort(p.begin(),p.end(),greater<>());
	int tmp=0;
	bool state=false;
	for(int i=0;i<m.size();++i){
		if(!state){
			tmp=m[i];
		}
		else{
			result+=m[i]*tmp;
		}
		state=!state;
	}
	if(m.size()%2==1){
		if(zeroCount==0) result+=m[m.size()-1];
	}
	state=false;
	for(int i=0;i<p.size();++i){
		if(!state){
			tmp=p[i];
		}
		else{
			result+=max(tmp+p[i],tmp*p[i]);
		}
		state=!state;
	}
	if(state){
		result+=p[p.size()-1];
	}
	cout<<result;
}