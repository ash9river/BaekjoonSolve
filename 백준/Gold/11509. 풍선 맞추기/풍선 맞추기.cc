#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int n;
vector<vector<int>> mapping(1000001,vector<int>());
vector<int> h;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>n;
    priority_queue<pair<int,int>> q;
    h.resize(n);
    for(int i=0;i<n;++i){
        cin>>h[i];
        q.push({h[i],-i});
    }
    int tmpValue=q.top().first;
    int tmpIdx=-q.top().second;
    q.pop();
    int result=1;
    if(n==1) cout<<result;
    else{
        while(!q.empty()){
            int crnValue=q.top().first;
            int crnIdx=-q.top().second;
            if(crnValue+1==tmpValue&&crnIdx>tmpIdx){
            }else{
                bool state=false;
                for(int i=0;i<mapping[crnValue+1].size();++i){
                    if(crnIdx>mapping[crnValue+1][i]){
                        mapping[crnValue+1][i]=1000001;
                        state=true;
                        break;
                    }
                }
                if(!state){
                    ++result;
                }
                mapping[tmpValue].push_back(tmpIdx);
            }
            tmpValue=crnValue;
            tmpIdx=crnIdx;
            q.pop();
        }
        cout<<result;
    }
}