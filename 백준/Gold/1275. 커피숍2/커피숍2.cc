#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
vector<ll> v;
vector<ll> seg;
ll init(int node,int start,int end){
	if(start==end){
		seg[node]=v[start];
	}
	else{
		int mid=(start+end)/2;
		seg[node]=init(node*2+1,start,mid)+init(node*2+2,mid+1,end);
	}
	return seg[node];
}
ll query(int node,int start,int end,int left,int right){
	if(start>right||end<left) return 0;
	if(left<=start&&end<=right) return seg[node];
	int mid=(start+end)/2;
	return query(node*2+1,start,mid,left,right)+query(node*2+2,mid+1,end,left,right);
}
void update(int thisNode,ll diff,int node,int start,int end){
	if(thisNode<start||thisNode>end) return;
	seg[node]+=diff;
	if(start!=end){
		int mid=(start+end)/2;
		update(thisNode,diff,node*2+1,start,mid);
		update(thisNode,diff,node*2+2,mid+1,end);
	}
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n,q;
	cin>>n>>q;
	v.resize(n);
	seg.resize(4*n);
	for(int i=0;i<n;++i){
		cin>>v[i];
	}
	init(0,0,n-1);
	ll x,y,a,b;
	for(int i=0;i<q;++i){
		cin>>x>>y>>a>>b;
		if(x>y) swap(x,y);
		cout<<query(0,0,n-1,x-1,y-1)<<"\n";
		ll diff=b-v[a-1];
		v[a-1]=b;
		update(a-1,diff,0,0,n-1);
	}
}