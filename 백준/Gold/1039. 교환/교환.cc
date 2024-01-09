#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;
int cache[11];
int bfs(string& n,int k){
	bool state=true;
	for(int i=1;i<n.size();++i){
		if(n[i]!='0'){
			state=false;
			break;
		}
	}
	if(state){
		if(n.size()<3) return -1;
		return stoi(n);
	}
	queue<pair<int,string>> q;
	q.push({0,n});
	int rslt=-1;
	while(!q.empty()){
		int cnt=q.front().first;
		string str=q.front().second;
		q.pop();
		if(cnt==k){
			rslt=max(rslt,stoi(str));
			continue;
		}
		for(int j=1;j<str.size();++j){
			if(str[j]!='0'){
				string tmp=str;
				swap(tmp[0],tmp[j]);
				if(cache[cnt+1]<stoi(tmp)){
					cache[cnt+1]=stoi(tmp);
					q.push({cnt+1,tmp});
				}
			}
		}
		for(int i=1;i<str.size()-1;++i){
			for(int j=i+1;j<str.size();++j){
				string tmp=str;
				swap(tmp[i],tmp[j]);
				if(cache[cnt+1]<stoi(tmp)){
					cache[cnt+1]=stoi(tmp);
					q.push({cnt+1,tmp});
				}
			}
		}
	}
	return rslt;
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	string n;
	int k;
	cin>>n>>k;
	cout<<bfs(n,k);
}	