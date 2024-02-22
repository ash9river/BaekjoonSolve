#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;//36퍼틀
vector<pair<int,int>> table;
vector<int> visited;
vector<bool> prime(9001,true);
int n;
void makePrime(){
    prime[0]=prime[1]=false;
    for(int i=2;i*i<=9000;++i){
        if(prime[i]){
            for(int j=i*i;j<=9000;j+=i){
                prime[j]=false;
            }
        }
    }
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    pair<int,int> a;
    pair<int,int> b;
    cin>>a.first>>a.second>>b.first>>b.second;
    cin>>n;
    table.resize(n);
    visited.resize(n,987654321);
    for(int i=0;i<n;++i){
        cin>>table[i].first>>table[i].second;
    }
    makePrime();
    priority_queue<pair<pair<int,int>,pair<int,int>>> q; //dis idx x y
    q.push({{0,-1},{a.first,a.second}});
    int ans=987654321;
    while(!q.empty()){
        int dis=-q.top().first.first;
        int idx=q.top().first.second;
        int crnX=q.top().second.first;
        int crnY=q.top().second.second;
        q.pop();
        int isPossibleToEnd=sqrt((crnX-b.first)*(crnX-b.first)+(crnY-b.second)*(crnY-b.second));
        if(prime[isPossibleToEnd]){
            ans=min(ans,dis+isPossibleToEnd);
        }
        for(int i=0;i<n;++i){
            int nxt=sqrt((crnX-table[i].first)*(crnX-table[i].first)+(crnY-table[i].second)*(crnY-table[i].second));
            if(prime[nxt]){
                if(dis==-1){
                    visited[i]=nxt;
                    q.push({{-nxt,i},{table[i].first,table[i].second}});
                }
                else{
                    if(visited[i]<=dis+nxt) continue;
                    visited[i]=dis+nxt;
                    q.push({{-(nxt+dis),i},{table[i].first,table[i].second}});
                }
            }
        }
    }
    if(ans==987654321){
        cout<<-1;
    }
    else cout<<ans;
}