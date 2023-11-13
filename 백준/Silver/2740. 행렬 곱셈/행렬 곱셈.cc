#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n,m,k;
	cin>>n>>m;
	vector<vector<int>> a(n,vector<int>(m));
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			cin>>a[i][j];
		}
	}
	cin>>m>>k;
	vector<vector<int>> b(m,vector<int>(k));
	for(int i=0;i<m;++i){
		for(int j=0;j<k;++j){
			cin>>b[i][j];
		}
	}
	vector<vector<int>> ans(n,vector<int>(k,0));

	for(int i=0;i<n;++i){
		for(int j=0;j<k;++j){
			for(int z=0;z<m;++z){
				ans[i][j]+=a[i][z]*b[z][j];
			}
		}
	}
	for(int i=0;i<n;++i){
		for(int j=0;j<k;++j){
			cout<<ans[i][j]<<" ";
		}
		cout<<"\n";
	}
}