#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define ll long long
using namespace std;
string a;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin>>a;
	int p;
	string tmp="";
	vector<int> val;
	vector<char> cp;
	for(int i=0;i<a.size();++i){
		if(a[i]=='+'||a[i]=='-'){
			val.push_back(stoi(tmp));
			cp.push_back(a[i]);
			tmp="";
		}
		else{
			tmp+=a[i];
		}
	}
	val.push_back(stoi(tmp));
	if(!cp.empty()){
		int result=val[0];
		for(int i=0;i<cp.size();++i){
			if(cp[i]=='-'){
				result-=val[i+1];
				for(int j=i+1;j<cp.size();++j){
					if(cp[j]=='-'){
						i=j-1;
						break;
					}
					else{
						result-=val[j+1];
					}
					if(j==cp.size()-1){
						i=cp.size();
					}
				}
			}
			else result+=val[i+1];
		}
		cout<<result;
	}else{
		cout<<val[0];
	}

}