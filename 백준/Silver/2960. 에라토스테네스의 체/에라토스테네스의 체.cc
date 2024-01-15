#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n,k;
	cin>>n>>k;
	vector<bool> Prime(1001,true);
	int gae=0;
	for(int i=2;i<=n;++i){
		if(Prime[i]){
			++gae;
			if(gae==k){
				cout<<i;
				break;
			}
			for(int j=i*i;j<=n;j+=i){
				if(Prime[j]) ++gae;
				Prime[j]=false;
				if(gae==k){
					cout<<j;
					break;
				}
			}
		}
	}
}