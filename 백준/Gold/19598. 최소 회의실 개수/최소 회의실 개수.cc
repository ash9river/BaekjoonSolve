#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n,a,b;
    cin>>n;
    priority_queue<pair<int,bool>> q; // 끝나면면 true
    for(int i=0;i<n;++i){
        cin>>a>>b;
        q.push({-a,false});
        q.push({-b,true});
    }
    int gae=1;
    int crntGae=0;
    while(!q.empty()){
        bool state=q.top().second;
        int t=-q.top().first;
        q.pop();
        if(state){
            --crntGae;
        }
        else{
            ++crntGae;
        }
        gae=max(gae,crntGae);
    }
    cout<<gae;
}