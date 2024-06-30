#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
bool isFriend[50][50];
bool visited[50];
int n;
int ans;
int bfs(int start){
    queue<pair<int,int>> q;
    q.push({0,start});
    visited[start]=true;
    int ret=0;
    while(!q.empty()){
        int depth=q.front().first;
        int cur=q.front().second;
        q.pop();
        if(depth>2) continue;
        ++ret;
        for(int i=0;i<n;++i){
            if(!visited[i]&&isFriend[i][cur]){
                q.push({depth+1,i});
                visited[i]=true;
            }
        }
    }
    return ret;
}
void init(int start){
    memset(visited,false,sizeof(visited));
    int tmpAns=0;
    tmpAns+=bfs(start);
    ans=max(tmpAns,ans);
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    string a;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>a;
        for(int j=0;j<n;++j){
            if(a[j]=='Y') isFriend[i][j]=true;
        }
    }
    for(int i=0;i<n;++i){
        init(i);
    }
    cout<<ans-1; 
}  