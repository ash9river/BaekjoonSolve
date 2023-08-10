#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
vector<pair<int,int>> tree(200001,pair<int,int>(-1,-1));
ll k;
int n;
ll num;
void dfs(ll root,ll startIdx){
	if(tree[root].first!=-1&&tree[root].second!=-1){
		if((((ll)1)<<startIdx)&k){
			dfs(tree[root].second,startIdx+1);
		}
		else dfs(tree[root].first,startIdx+1);
	}
	else if(tree[root].first!=-1){
        dfs(tree[root].first,startIdx);
    }
    else if(tree[root].second!=-1){
        dfs(tree[root].second,startIdx);
    }
    else{
        num=root;
        return;
    }
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin>>n;
	int u,v;
	for(int i=1;i<=n;++i){
		cin>>u>>v;
		tree[i].first=u;
		tree[i].second=v;
	}
	cin>>k;
	k-=1;
    dfs(1,0);
    cout<<num;
}