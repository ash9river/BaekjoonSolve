#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int t;
	cin>>t;
	while(t-->0){
		int n,m;
		cin>>n>>m;
		int a,b;
		for(int i=0;i<m;++i){
			cin>>a>>b;
		}
		cout<<n-1<<"\n";
	}
}