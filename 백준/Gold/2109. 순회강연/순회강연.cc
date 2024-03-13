#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n,a,b;
    cin>>n;
    priority_queue<pair<int,int>> q;
    for(int i=0;i<n;++i){
        cin>>a>>b;
        q.push({a,b});
    }
    vector<int> table(10001,0);
    while(!q.empty()){
        int val=q.top().first;
        int day=q.top().second;
        q.pop();
        for(int i=day;i>0;--i){
            if(table[i]==0){
                table[i]=val;
                break;
            } 
            else continue;
        }
    }
    int ans=0;
    for(int k:table) ans+=k;
    cout<<ans;
}