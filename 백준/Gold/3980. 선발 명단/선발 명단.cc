#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
vector<vector<int>> v;
vector<int> picker;
vector<bool> visited(11,false);
int ans;
void pick(int toPick){
    if(toPick==0){
        int tmpAns=0;
        if(picker.size()<11) return;
        for(int i=0;i<picker.size();++i){
            tmpAns+=v[i][picker[i]];
        }
        ans=max(ans,tmpAns);
        return;
    }
    for(int i=0;i<11;++i){
        if(!visited[i]){
            if(v[picker.size()][i]==0) continue;
            visited[i]=true;
            picker.push_back(i);
            pick(toPick-1);
            picker.pop_back();
            visited[i]=false;
        }
    }
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t-->0){
        v.resize(11,vector<int>(11,0));
        for(int i=0;i<11;++i){
            for(int j=0;j<11;++j){
                cin>>v[i][j];
            }
        }
        pick(11);
        cout<<ans<<"\n";
        ans=0;
        visited.resize(11,false);
    }
}