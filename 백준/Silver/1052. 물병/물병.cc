#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n,k;
	cin>>n>>k;
	int startBit,lastBit=-1;
	int bitGae=0;
	if(n<=k){
		cout<<0;
	}
	else{
		bool state=true;
		for(int i=31;i>=0;--i){
			if(n&(1<<i)){
				++bitGae;
				if(state){
					if(bitGae==k){
						lastBit=i;
						state=false;
					}
				}
				if(bitGae>k) startBit=i;
			}
		}
		int gae=(1<<startBit);
		for(int i=startBit+1;i<lastBit;++i){
			if(n&(1<<i)) continue;
			else gae+=(1<<i);
		}
		if(bitGae<=k) cout<<0;
		else cout<<gae;
	}
}