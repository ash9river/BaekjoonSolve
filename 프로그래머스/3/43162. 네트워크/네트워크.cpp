#include <string>
#include <vector>
using namespace std;
bool state=false;
vector<vector<int>> graph;
bool visited[200];
void dfs(int src){
    if(visited[src]) return;
    state=true;
    visited[src]=true;
    for(int i=0;i<graph[src].size();++i){
        int nxt=graph[src][i];
        dfs(nxt);
    }
}
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    int cSize=computers.size();
    graph.resize(cSize);
    for(int i=0;i<cSize;++i){
        for(int j=0;j<cSize;++j){
            if(computers[i][j]==1){
                if(i==j) continue;
                graph[i].push_back(j);
            }
        }
    }
    for(int i=0;i<cSize;++i){
        state=false;
        dfs(i);
        if(state) ++answer;
    }
    return answer;
}