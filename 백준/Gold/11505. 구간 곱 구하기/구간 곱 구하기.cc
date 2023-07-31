#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
#define mod 1000000007
using namespace std;
vector<ll> tree;
vector<ll> a;
ll init(int node,int start,int end){
    if(start==end){
        tree[node]=a[start]%mod;
    }
    else{
        int mid=(start+end)/2;
        tree[node]=(init(2*node+1,start,mid)%mod)*(init(2*node+2,mid+1,end)%mod);
        tree[node]%=mod;
    }
    return tree[node];
}
ll query(int node,int start,int end,int left,int right){
    if(start>right||end<left) return 1;
    else if(start>=left&&end<=right){
        return tree[node];
    }
    else{
        int mid=(start+end)/2;
        return query(2*node+1,start,mid,left,right)%mod*query(2*node+2,mid+1,end,left,right)%mod;
    }
}
void update(int thisNode,ll after,int node,int start,int end){
    if(thisNode<start||thisNode>end) return;
    if(start==end){
        tree[node]=after;
        return;
    }
    int mid=(start+end)/2;
    update(thisNode,after,2*node+1,start,mid);
    update(thisNode,after,2*node+2,mid+1,end);
    tree[node]=tree[2*node+1]*tree[2*node+2]%mod;
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n,m,k;
    cin>>n>>m>>k;
    a.resize(n);
    tree.resize(4*n);
    for(int i=0;i<n;++i) cin>>a[i];
    init(0,0,n-1);
    int p,b;
    for(int i=0;i<m+k;++i){
        cin>>p>>b;
        if(p==1){
            ll c;
            cin>>c;
            a[b-1]=c;
            update(b-1,c,0,0,n-1);
        }
        else{
            int c;
            cin>>c;
            cout<<query(0,0,n-1,b-1,c-1)%mod<<"\n";
        }
    }
}