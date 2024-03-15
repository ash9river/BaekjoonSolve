#include <iostream>
#include <vector>
#include <deque>
#include <tuple>
#include <algorithm>
#define ll long long
using namespace std;
ll table[101][101];
bool v[101][101][2];
int n,m,k;
ll s(int y,int x){
    if(y==0&&x==0) return 1;
    else if(y==0){
        if(!v[y][x][1]) return s(y,x-1);
        return 0;
    }
    else if(x==0){
        if(!v[y][x][0]) return s(y-1,x);
        return 0;
    }
    ll& ret=table[y][x];
    if(ret!=-1) return ret;
    ret=0;
    if(!v[y][x][0]) ret+=s(y-1,x);
    if(!v[y][x][1]) ret+=s(y,x-1);
    return ret;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>n>>m>>k;
    fill(&table[0][0],&table[100][101],-1);
    int a,b,c,d;
    for(int i=0;i<k;++i){
        cin>>a>>b>>c>>d;
        if(a<c||b<d){
            swap(a,c);
            swap(b,d);
        }
        if(a>c) v[a][b][0]=true; // y
        else v[a][b][1]=true; // x
    }
    ll ans=s(n,m);
    ans=max(ans,0LL);
    cout<<ans;
}