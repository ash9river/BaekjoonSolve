#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0;i<n;++i){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    vector<bool> visited(n,false);
    for(int i=0;i<n;++i){
        int val=v[i];
        if(visited[val]){
            for(int j=val;j<=n;j+=k){
                if(!visited[j]){
                    visited[j]=true;
                    break;
                }
            }
        }
        else{
            visited[val]=true;
        }
    }
    bool state=true;
    for(int i=1;i<=n;++i){
        if(!visited[i]){
            state=false;
            break;
        }
    }
    if(state) cout<<1;
    else cout<<0;
}