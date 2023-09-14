#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n;
	cin>>n;
	vector<int> board(3,0);
	vector<int> minR(3,0);
	vector<int> maxR(3,0);
	vector<int> tmp(3,0);
	for(int i=0;i<3;++i){
		cin>>board[i];
		minR[i]=maxR[i]=board[i];
	}
	for(int i=1;i<n;++i){
		for(int j=0;j<3;++j) cin>>board[j];
		for(int j=0;j<3;++j) tmp[j]=minR[j];
		minR[0]=min(tmp[0],tmp[1])+board[0];
		minR[1]=min({tmp[0],tmp[1],tmp[2]})+board[1];
		minR[2]=min(tmp[1],tmp[2])+board[2];
		for(int j=0;j<3;++j) tmp[j]=maxR[j];
		maxR[0]=max(tmp[0],tmp[1])+board[0];
		maxR[1]=max({tmp[0],tmp[1],tmp[2]})+board[1];
		maxR[2]=max(tmp[1],tmp[2])+board[2];
	}
	cout<<max({maxR[0],maxR[1],maxR[2]})<<" "<<min({minR[0],minR[1],minR[2]});
}
