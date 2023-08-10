#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
int v,e;
vector<int> sccId;
vector<int> visited;
vector<vector<int>> board;
stack<int> stk;
int sccCounter,vertexCounter;
int scc(int start){
    int ret=visited[start]=vertexCounter++;
    stk.push(start);
    for(int i=0;i<board[start].size();++i){
        int nxt=board[start][i];
        if(visited[nxt]==-1) ret=min(ret,scc(nxt));
        else if(sccId[nxt]==-1) ret=min(ret,visited[nxt]);
    }
    if(ret==visited[start]){
        while(true){
            int t=stk.top();
            stk.pop();
            sccId[t]=sccCounter;
            if(t==start) break;
        }
        ++sccCounter;
    }
    return ret;
}
vector<int> tarjanSCC(){
    sccId.resize(v,-1);
    visited.resize(v,-1);
    for(int i=0;i<board.size();++i){
        if(visited[i]==-1) scc(i);
    }
    return sccId;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>v>>e;
    board.resize(v,vector<int>());
    int a,b;
    for(int i=0;i<e;++i){
        cin>>a>>b;
        board[a-1].push_back(b-1);
    }
    vector<int> ans=tarjanSCC();
    vector<vector<int>> rslt(sccCounter,vector<int>());
    for(int i=0;i<ans.size();++i){
        int k=ans[i];
        rslt[k].push_back(i+1);
    }
    sort(rslt.begin(),rslt.end());
    cout<<sccCounter<<'\n';
    for(int i=0;i<sccCounter;++i){
        for(int j=0;j<rslt[i].size();++j){
            cout<<rslt[i][j]<<" ";
        }
        cout<<"-1\n";
    }

}