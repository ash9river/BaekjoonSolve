#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
vector<bool> doesRobotExist;
int ans=1;
int n,k;
bool isEnd(){
    int gae=0;
    for(int i=0;i<2*n;++i){
        if(v[i]==0) ++gae;
    }
    if(gae>=k) return true;
    return false;
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>n>>k;
    v.resize(2*n,0);
    for(int i=0;i<2*n;++i){
        cin>>v[i];
    }
    doesRobotExist.resize(2*n,false);
    while(true){
        // rotate
        vector<int> tmp(2*n,0);
        vector<bool> visitedTmp(2*n,false);
        for(int i=1;i<2*n;++i){
            tmp[i]=v[i-1];
            visitedTmp[i]=doesRobotExist[i-1];
        }
        tmp[0]=v[2*n-1];
        v=tmp;
        doesRobotExist=visitedTmp;
        doesRobotExist[n-1]=false;
        // move
        for(int i=n-2;i>=0;--i){
            if(v[i+1]>0&&!doesRobotExist[i+1]&&doesRobotExist[i]){
                --v[i+1];
                doesRobotExist[i+1]=true;
                doesRobotExist[i]=false;
            }
        }
        doesRobotExist[n-1]=false;
        // lay down
        if(v[0]>0){
            --v[0];
            doesRobotExist[0]=true;
        }
        if(isEnd()) break;
        ++ans;
    }
    cout<<ans;
}