#include <string>
#include <vector>

using namespace std;
int parent[201];
int rankOfParent[201];
int findParent(int vertex){
    if(parent[vertex]!=vertex) parent[vertex]=findParent(parent[vertex]);
    return parent[vertex];
}
void unionByRank(int a,int b){
    int parentA=findParent(a);
    int parentB=findParent(b);
    if(parentA!=parentB){
        if(rankOfParent[parentA]>rankOfParent[parentB]){
            swap(parentA,parentB);
        }
        parent[parentA]=parentB;
        if(rankOfParent[parentA]==rankOfParent[parentB]) ++rankOfParent[parentB];
    }
}
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for(int i=0;i<n;++i) {
        parent[i]=i;
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(i!=j){
                if(computers[i][j]==1){
                    unionByRank(i,j);
                }
            }
        }
    }
    for(int i=0;i<n;++i){
        if(parent[i]==i) ++answer;
    }
    return answer;
}