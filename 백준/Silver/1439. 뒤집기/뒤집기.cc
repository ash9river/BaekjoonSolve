#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	string str;
	int a=0,b=0;
	cin>>str;
	bool state=false;//0=false,1=true
	if(str[0]=='1') state=true;
	if(state) ++a;
	else ++b;
	for(int i=1;i<str.size();++i){
		if(!state){
			if(str[i]=='1'){
				++a;
				state=true;
			}
		}
		else{
			if(str[i]=='0'){
				++b;
				state=false;
			}
		}
	}
	cout<<min(a,b);
}