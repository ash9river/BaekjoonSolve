#include <iostream>
#include <vector>
#include <tuple>
#include <deque>
#include <algorithm>
using namespace std;
vector<vector<int>> v(50,vector<int>(50));
deque<int> picker;
int n,m,k,r,c,s;
int ans=987654321;
void rotateArray(vector<vector<int>>& cache,int y,int x,int dis){
    vector<vector<int>> tmpV=cache;
    for(int i=x-dis+1;i<=x+dis;++i){
        tmpV[y-dis][i]=cache[y-dis][i-1];
    }
    for(int i=y-dis+1;i<=y+dis;++i){
        tmpV[i][x+dis]=cache[i-1][x+dis];
    }
    for(int i=x+dis-1;i>=x-dis;--i){
        tmpV[y+dis][i]=cache[y+dis][i+1];
    }
    for(int i=y+dis-1;i>=y-dis;--i){
        tmpV[i][x-dis]=cache[i+1][x-dis];
    }
    cache=tmpV;
}
void pick(vector<tuple<int,int,int>>& item,vector<bool>& visited,int gae){
    if(gae==k){
        vector<vector<int>> cache(n,vector<int>(m));
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                cache[i][j]=v[i][j];
            }
        }

        for(int i=0;i<k;++i){
            for(int j=1;j<=get<2>(item[picker[i]]);++j){
                rotateArray(cache,get<0>(item[picker[i]]),get<1>(item[picker[i]]),j);
            }
        }
        for(int i=0;i<n;++i){
            int tmp=0;
            for(int j=0;j<m;++j){
                tmp+=cache[i][j];
            }
            ans=min(ans,tmp);
        }
        return;
    }
    for(int i=0;i<k;++i){
        if(!visited[i]){
            visited[i]=true;
            picker.push_back(i);
            pick(item,visited,gae+1);
            visited[i]=false;
            picker.pop_back();
        }
    }
}


int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>n>>m>>k;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin>>v[i][j];
        }
    }
    vector<tuple<int,int,int>> item(k);
    for(int i=0;i<k;++i){
        cin>>r>>c>>s;
        --r;
        --c;
        item[i]={r,c,s};
    }
    vector<bool> visited(k,false);
    pick(item,visited,0);
    cout<<ans;
}