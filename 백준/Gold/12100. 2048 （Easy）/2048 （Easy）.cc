#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,maxAns;
void boardUp(vector<vector<int>>& cache){
    vector<vector<bool>> visited(20,vector<bool>(20,false));
    for(int j=0;j<n;++j){
        for(int i=0;i<n;++i){
            if(cache[i][j]!=0){
                for(int k=i-1;k>=0;--k){
                    if(cache[k][j]!=0){
                        if(cache[k][j]==cache[k+1][j]&&!visited[k][j]){
                            cache[k][j]+=cache[k+1][j];
                            cache[k+1][j]=0;
                            visited[k][j]=true;
                        }
                        break;
                    }
                    else{
                        cache[k][j]=cache[k+1][j];
                        cache[k+1][j]=0;
                    }
                }
            }
        }
    }
}
void boardDown(vector<vector<int>>& cache){
    vector<vector<bool>> visited(20,vector<bool>(20,false));
    for(int j=0;j<n;++j){
        for(int i=n-1;i>=0;--i){
            if(cache[i][j]!=0){
                for(int k=i+1;k<=n-1;++k){
                    if(cache[k][j]!=0){
                        if(cache[k][j]==cache[k-1][j]&&!visited[k][j]){
                            cache[k][j]+=cache[k-1][j];
                            cache[k-1][j]=0;
                            visited[k][j]=true;
                        }
                        break;
                    }
                    else{
                        cache[k][j]=cache[k-1][j];
                        cache[k-1][j]=0;
                    }
                }
            }
        }
    }
}
void boardLeft(vector<vector<int>>& cache){
    vector<vector<bool>> visited(20,vector<bool>(20,false));
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(cache[i][j]!=0){
                for(int k=j-1;k>=0;--k){
                    if(cache[i][k]!=0){
                        if(cache[i][k]==cache[i][k+1]&&!visited[i][k]){
                            cache[i][k]+=cache[i][k+1];
                            cache[i][k+1]=0;
                            visited[i][k]=true;
                        }
                        break;
                    }
                    else{
                        cache[i][k]=cache[i][k+1];
                        cache[i][k+1]=0;
                    }
                }
            }
        }
    }
}
void boardRight(vector<vector<int>>& cache){
    vector<vector<bool>> visited(20,vector<bool>(20,false));
    for(int i=0;i<n;++i){
        for(int j=n-1;j>=0;--j){
            if(cache[i][j]!=0){
                for(int k=j+1;k<n;++k){
                    if(cache[i][k]!=0){
                        if(cache[i][k]==cache[i][k-1]&&!visited[i][k]){
                            cache[i][k]+=cache[i][k-1];
                            cache[i][k-1]=0;
                            visited[i][k]=true;
                        }
                        break;
                    }
                    else{
                        cache[i][k]=cache[i][k-1];
                        cache[i][k-1]=0;
                    }
                }
            }
        }
    }
}
void startGame(int idx,vector<vector<int>> v){
    if(idx==5){
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                maxAns=max(maxAns,v[i][j]);
            }
        }
        return;
    }
    vector<vector<vector<int>>> cache(4,vector<vector<int>>(n,vector<int>(n)));
    for(int i=0;i<4;++i){
        for(int j=0;j<n;++j){
            for(int k=0;k<n;++k){
                cache[i][j][k]=v[j][k];
            }
        }
    }
    boardUp(cache[0]);
    boardRight(cache[1]);
    boardDown(cache[2]);
    boardLeft(cache[3]);
    for(int i=0;i<4;++i){
        startGame(idx+1,cache[i]);
    }
}

void init(){
    vector<vector<int>> table(n,vector<int>(n));
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            cin>>table[i][j];
        }
    }
    startGame(0,table);
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>n;
    init();
    cout<<maxAns;
}