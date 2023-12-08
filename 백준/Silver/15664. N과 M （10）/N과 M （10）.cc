#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;
vector<int> table;
deque<int> picker;
int n,m;
void pick(int toPick,int idx){
    if(toPick==0){
        for(int i=0;i<picker.size()-1;++i){
            cout<<picker[i]<<" ";
        }
        cout<<picker[picker.size()-1]<<"\n";
        return;
    }
    for(int i=idx;i<n;++i){
        if(i==idx){
            picker.push_back(table[i]);
            pick(toPick-1,i+1);
            picker.pop_back();
        }
        else{
            if(table[i]!=table[i-1]){
                picker.push_back(table[i]);
                pick(toPick-1,i+1);
                picker.pop_back();
            }
        }
    }
}
void init(){
    table.resize(n);
    for(int i=0;i<n;++i){
        cin>>table[i];
    }
    sort(table.begin(),table.end());
    pick(m,0);
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    init();
}