#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	string str;
	int b;
	cin>>str>>b;
	vector<int> table(26);
	for(int i=0;i<26;++i){
		table[i]=10+i;
	}
	int ans=0;
	int ptr=1;
	for(int i=str.size()-1;i>=0;--i){
		if(str[i]>='0'&&str[i]<='9'){
			ans+=(str[i]-'0')*ptr;
			ptr*=b;
		}
		else{
			ans+=table[str[i]-'A']*ptr;
			ptr*=b;
		}
	}
	cout<<ans;
}