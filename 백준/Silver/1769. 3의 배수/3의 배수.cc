#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	string a;
	cin>>a;
	int x=0,gae=0;
	if(a.size()!=1) ++gae;
	for(int i=0;i<a.size();++i){
		x+=a[i]-'0';
	}
	while(true){
		if(x<10) break;
		++gae;
		int tmp=0;
		while(x>0){
			tmp+=x%10;
			x/=10;
		}
		x=tmp;
	}
	cout<<gae<<"\n";
	if(x==3||x==6||x==9) cout<<"YES";
	else cout<<"NO";
}