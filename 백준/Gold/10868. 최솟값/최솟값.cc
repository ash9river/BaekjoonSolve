#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
vector<ll> tree;
vector<ll> seg;
int n,m;
ll init(int node,int start,int end){
	if(start==end){
		seg[node]=tree[start];
	}
	else{
		int mid=(start+end)/2;
		ll left=init(node*2,start,mid);
		ll right=init(node*2+1,mid+1,end);
		seg[node]=min(left,right);
	}
	return seg[node];
}

void init(){
	for(int i=1;i<=n;++i){
		cin>>tree[i];
	}
	init(1,1,n);
}
ll query(int node,int start,int end,int left,int right){
	if(start>right||end<left){
		return 1000000001;
	}
	else if(start>=left&&end<=right){
		return seg[node];
	}
	else{
		int mid=(start+end)/2;
		ll leftVal=query(node*2,start,mid,left,right);
		ll rightVal=query(node*2+1,mid+1,end,left,right);
		return min(leftVal,rightVal);
	}
}



void query(int a,int b){
	cout<<query(1,1,n,a,b)<<"\n";
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin>>n>>m;
	tree.resize(n+1);
	seg.resize(4*(n+1));
	init();
	int a,b;
	for(int i=0;i<m;++i){
		cin>>a>>b;
		query(a,b);
	}
}