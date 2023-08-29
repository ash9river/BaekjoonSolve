#include <iostream>
#include <vector>
#include <queue>
#include <cctype>
#include <algorithm>
#define INF 987654321
using namespace std;
int n,p;
int capacity[401][401],flow[401][401];
int networkFlow(){
    int totalFlow=0;
     while(true){ 
        vector<int> parent(n+1,-1);
        queue<int> q;
        parent[1]=1;
        q.push(1);
        while(!q.empty()&&parent[2]==-1){
            int now=q.front();
            q.pop();
            for(int nxt=1;nxt<=n;++nxt){
                if(capacity[now][nxt]-flow[now][nxt]>0&&parent[nxt]==-1){
                    q.push(nxt);
                    parent[nxt]=now;
                }
            }
        }
         if(parent[2]==-1) break; 
        int amount=INF;
        for(int p=2;p!=1;p=parent[p]){
            amount=min(capacity[parent[p]][p]-flow[parent[p]][p],amount);
        }
        for(int p=2;p!=1;p=parent[p]){
            flow[parent[p]][p]+=amount;
            flow[p][parent[p]]-=amount;
        }
        totalFlow+=amount;
    } 
    return totalFlow;
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>n>>p;
    int a,b;
    for(int i=0;i<p;++i){
        cin>>a>>b;
        capacity[a][b]+=1;
    }
    cout<<networkFlow();
}