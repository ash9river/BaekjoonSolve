#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
vector<int> seg;
int n,k;
int init(int node,int start,int end){
	if(start==end){
		seg[node]=v[start];
	}
	else{
		int mid=(start+end)/2;
		seg[node]=init(node*2+1,start,mid)*init(node*2+2,mid+1,end);
	}
	return seg[node];
}
int query(int node,int start,int end,int left,int right){
	if(start>right||end<left) return 1;
	else if(start>=left&&end<=right) return seg[node];
	else{
		int mid=(start+end)/2;
		return query(2*node+1,start,mid,left,right)*query(2*node+2,mid+1,end,left,right);
	}
}
int update(int thisNode,int diff,int node,int start,int end){
	if(thisNode<start||thisNode>end) return seg[node];
	if(start==end) return seg[node]=diff;
	else{
		int mid=(start+end)/2;
		seg[node]=update(thisNode,diff,node*2+1,start,mid)*update(thisNode,diff,node*2+2,mid+1,end);
	}
	return seg[node];
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	while(true){
		cin>>n>>k;
		if(cin.eof()) break;
		int a,b;
		v.resize(n,0);
		seg.resize(4*n,0);
		for(int i=0;i<n;++i){
			cin>>a;
			if(a>0) v[i]=1;
			else if(a==0) v[i]=0;
			else v[i]=-1;
		}
		init(0,0,n-1);
		string p;
		string ans="";
		for(int i=0;i<k;++i){
			cin>>p>>a>>b;
			if(p=="C"){
				if(b>0) b=1;
				else if(b==0) b=0;
				else b=-1;
				update(a-1,b,0,0,n-1);
			}
			else{
				int tmpAns=query(0,0,n-1,a-1,b-1);
				if(tmpAns>0) ans+="+";
				else if(tmpAns==0) ans+="0";
				else ans+="-";
			}
		}
		cout<<ans<<"\n";
	}
}