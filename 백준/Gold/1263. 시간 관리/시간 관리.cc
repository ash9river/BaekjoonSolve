#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    priority_queue<pair<int,int>> q;
    cin>>n;
    int t,s;
    for(int i=0;i<n;++i){
        cin>>t>>s;
        q.push({s,t});
    }
    int crnTime=1000000;
    while(!q.empty()){
        int deadLine=q.top().first;
        int cost=q.top().second;
        q.pop();
        if(deadLine<crnTime){
            crnTime=deadLine;
        }
        if(crnTime-cost<0){
            crnTime=-1;
            break;
        }
        crnTime-=cost;
    }
    cout<<crnTime;
}