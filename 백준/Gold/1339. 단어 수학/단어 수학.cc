#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int time(int t){
    if(t==0) return 1;
    int mm=1;
    for(int i=0;i<t;++i){
        mm*=10;
    }
    return mm;
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    vector<pair<int,string>> v(n);
    map<char,int> table;
    map<char,int> m;
    priority_queue<pair<int,char>> q;
    string a;
    int result=0;
    int ptr=9;
    for(int i=0;i<n;++i){
        cin>>a;
        v[i]={-a.size(),a};
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;++i){
        int tmpSize=v[i].second.size();
        for(int j=0;j<tmpSize;++j){
            if(table.count(v[i].second[j])>0){
                int tmp=table[v[i].second[j]];
                table[v[i].second[j]]=tmp+time(tmpSize-1-j);
            }else{
                table[v[i].second[j]]=time(tmpSize-1-j);
            }
        }
    }
    for(auto it=table.begin();it!=table.end();++it){
        char key=it->first;
        int value=it->second;
        q.push({value,key});
    }
    while(!q.empty()){
        char key=q.top().second;
        int val=q.top().first;
        result+=val*ptr;
        q.pop();
        ptr--;
        if(ptr<0) break;
    }
    cout<<result;
}