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
        for(int k:picker) cout<<k<<" ";
        cout<<"\n";
        return;
    }
    for(int i=0;i<n;++i){
        picker.push_back(table[i]);
        pick(toPick-1,i);
        picker.pop_back();
    }
}

void init(){
    
    pick(m,0);
    
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    table.resize(n);
    for(int i=0;i<n;++i){
        cin>>table[i];
    }
    sort(table.begin(),table.end());
    init();
}