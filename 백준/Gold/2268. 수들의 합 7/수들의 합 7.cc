#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
vector<ll> seg;
vector<ll> v;
int n,m;
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
    else if(start>=left&&end<=right) return seg[node];
    else{
        int mid=(start+end)/2;
        return query(node*2+1,start,mid,left,right)+query(node*2+2,mid+1,end,left,right);
    }

}
void update(int thisNode,int diff,int node,int start,int end){
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
    cin>>n>>m;
    v.resize(n,0);
    seg.resize(4*n);
    init(0,0,n-1);
    int a,b,c;
    for(int i=0;i<m;++i){
        cin>>a>>b>>c;
        if(a==0){
            // query
            --b;
            --c;
            if(b>c) swap(b,c);
            cout<<query(0,0,n-1,b,c)<<"\n";
        }
        else{
            // update
            --b;
			int tmp=c;
            c=c-v[b];
            v[b]=tmp;
            update(b,c,0,0,n-1);
        }
    }
}