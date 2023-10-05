#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int,int>> v(1000001);
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n,m;
    cin>>n>>m;
    vector<int> table(n);
    for(int i=0;i<n;++i){
        cin>>table[i];
    }
    for(int i=1;i<n-1;++i){
        v[table[i]].first=table[i-1];
        v[table[i]].second=table[i+1];
    }
    if(n!=1){//n==2 case think
        v[table[0]].first=table[n-1];
        v[table[0]].second=table[1];
        v[table[n-1]].first=table[n-2];
        v[table[n-1]].second=table[0];
    } 
    else{
        v[table[0]].first=v[table[0]].second=table[0];
    }
    string command;
    int a,b,tmp;
    for(int i=0;i<m;++i){
        cin>>command>>a;
        if(command=="BN"){
            cin>>b;
            cout<<v[a].second<<"\n";
            v[b].first=a;
            v[b].second=v[a].second;
            v[a].second=b;
            v[v[b].second].first=b;
        }
        else if(command=="BP"){
            cin>>b;
            cout<<v[a].first<<"\n";
            v[b].first=v[a].first;
            v[b].second=a;
            v[v[b].first].second=b;
            v[a].first=b;
        }
        else if(command=="CN"){
            tmp=v[a].second;
            cout<<tmp<<"\n";
            v[a].second=v[tmp].second;
            v[v[tmp].second].first=a;
            v[tmp].first=v[tmp].second=0;
        }
        else{
            tmp=v[a].first;
            cout<<tmp<<"\n";
            v[a].first=v[tmp].first;
            v[v[tmp].first].second=a;
            v[tmp].first=v[tmp].second=0;
        }
    }
}