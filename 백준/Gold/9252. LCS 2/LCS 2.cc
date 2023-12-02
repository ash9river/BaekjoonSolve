#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	string a,b;
	cin>>a>>b;
	vector<vector<int>> v(a.size()+1,vector<int>(b.size()+1,0));
	int y=a.size(),x=b.size();
	for(int i=1;i<y+1;++i){
		for(int j=1;j<x+1;++j){
			if(a[i-1]==b[j-1]) v[i][j]=v[i-1][j-1]+1;
			else{
				v[i][j]=max(v[i][j-1],v[i-1][j]);
			}
		}
	}
	cout<<v[y][x]<<"\n";
	vector<char> ans;
	while(y>0&&x>0){
		if(v[y][x]==v[y-1][x-1]+1){
			if(a[y-1]==b[x-1]){
				ans.push_back(a[y-1]);
				--y;
				--x;
			}
			else{
				if(v[y][x]==v[y-1][x]) --y;
				else --x;
			}
		}
		else{
			if(v[y][x]==v[y][x-1]) --x;
			else --y;
		}
	}
	for(int i=ans.size()-1;i>=0;--i){
		cout<<ans[i];
	}
}