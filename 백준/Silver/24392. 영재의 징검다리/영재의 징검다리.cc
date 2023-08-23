#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define ll long long
#define mod 1000000007
using namespace std;
ll board[1000][1000];
ll cache[1000][1000];
int n,m;
ll path(int y,int x){
    if(x<0||x>=m) return 0;
    if(board[y][x]==0) return 0;
    if(y==n-1) return 1;
    ll& ret=cache[y][x];
    if(ret!=-1) return ret;
    ret=0;
    return ret=(path(y+1,x-1)+path(y+1,x)+path(y+1,x+1))%mod;
}
ll pathInit(){
    ll ret=0;
    memset(cache,-1,sizeof(cache));
    for(int i=0;i<m;++i){
        ret+=path(0,i);
        ret%=mod;
    }
    return ret;
}


int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin>>board[i][j];
        }
    }
    cout<<pathInit();
}