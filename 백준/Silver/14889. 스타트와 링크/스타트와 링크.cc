#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;
vector<vector<int>> v;
deque<int> picker;
vector<bool> visited;
int n,ans=987654321;
void pick(int toPick,int idx){
    if(toPick==n/2){
        deque<int> antiPick;
        for(int i=0;i<n;++i){
            bool state=false;
            for(int j=0;j<picker.size();++j){
                if(picker[j]==i){
                    state=true;
                    break;
                }
            }
            if(!state){
                antiPick.push_back(i);
            }
        }
        int a=0,b=0;
        for(int i=0;i<n/2;++i){
            for(int j=0;j<n/2;++j){
                if(i==j) continue;
                a+=v[picker[i]][picker[j]];
                b+=v[antiPick[i]][antiPick[j]];
            }
        }
        ans=min(ans,abs(a-b));
        return;
    }
    for(int i=idx;i<n;++i){
        if(!visited[i]){
            visited[i]=true;
            picker.push_back(i);
            pick(toPick+1,i+1);
            picker.pop_back();
            visited[i]=false;
        }
    }
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>n;
    v.resize(n,vector<int>(n));
    visited.resize(n,false);
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            cin>>v[i][j];
        }
    }
    pick(0,0);
    cout<<ans;
}