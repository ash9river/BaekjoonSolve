#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
string a,b;
set<string> s;
bool state=false;
void makeString(string str){
	if(str.size()<a.size()) return;
	if(state) return;
	if(str.back()=='A'){
		string str1=str.substr(0,str.size()-1);
		if(str1==a){
			state=true;
			return;
		}
		if(s.find(str1)==s.end()){
			s.insert(str1);
			makeString(str1);
		}
	}
	if(str[0]=='B'){
		string str2=str.substr(1,str.size());
		reverse(str2.begin(),str2.end());
		if(str2==a){
			state=true;
			return;
		}
		if(s.find(str2)==s.end()){
			s.insert(str2);
			makeString(str2);
		}
	}
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin>>a>>b;
	makeString(b);
	if(state) cout<<1;
	else cout<<0;
}