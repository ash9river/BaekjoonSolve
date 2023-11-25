#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n,l;
    cin>>n>>l;
    priority_queue<pair<int,int>> q;
    vector<int> table(n);
    for(int i=0;i<n;++i){
        cin>>table[i];
    }
    for(int i=0;i<n;++i){
        q.push({-table[i],i});
        while(true){
            int val=-q.top().first;
            int idx=q.top().second;
            if(idx<i-l+1){
                q.pop();
            }
            else{
                cout<<val<<" ";
                break;
            }
        }
    }
}