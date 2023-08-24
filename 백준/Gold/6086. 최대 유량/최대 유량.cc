#include <iostream>
#include <vector>
#include <queue>
#include <cctype>
#include <algorithm>
#define INF 987654321
using namespace std;
int n,p;
int capacity[52][52],flow[52][52];
int networkFlow(){
    int totalFlow=0;
    while(true){
        vector<int> parent(52,-1);
        queue<int> q;
        parent[0]=0;
        q.push(0);
        while(!q.empty()&&parent[25]==-1){
            int now=q.front();
            q.pop();
            for(int nxt=0;nxt<52;++nxt){
                if(capacity[now][nxt]-flow[now][nxt]>0&&parent[nxt]==-1){
                    q.push(nxt);
                    parent[nxt]=now;
                }
            }
        }
        if(parent[25]==-1) break;
        int amount=INF;
        for(int p=25;p!=0;p=parent[p]){
            amount=min(capacity[parent[p]][p]-flow[parent[p]][p],amount);
        }
        for(int p=25;p!=0;p=parent[p]){
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
    cin>>n;
    char a,b;
    int c;
    for(int i=0;i<n;++i){
        cin>>a>>b>>c;
        int keyA=0,KeyB=0;
        if(islower(a)) keyA=a-'a'+26;
        else keyA=a-'A';
        if(islower(b)) KeyB=b-'a'+26;
        else KeyB=b-'A';
        capacity[keyA][KeyB]+=c;
        capacity[KeyB][keyA]+=c;
    }
    cout<<networkFlow();
}