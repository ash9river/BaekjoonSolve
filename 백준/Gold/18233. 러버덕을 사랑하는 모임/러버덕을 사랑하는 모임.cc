#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
vector<pair<int,int>> v;
vector<tuple<int,int,int>> picker; //최소+증분+인덱스
bool state=false;
vector<int> ans;
int n,p,e;

void pick(int toPick,int idx){
    if(toPick==0&&!state){
        int minSum=0;
        int dx=0;
        for(int i=0;i<p;++i){
            minSum+=get<0>(picker[i]);
            dx+=get<1>(picker[i]);
        }
        if(minSum<=e&&e<=minSum+dx){
            state=true;
            dx=e-minSum;
            for(int i=0;i<p;++i){
                if(dx>=get<1>(picker[i])){
                    ans[get<2>(picker[i])]=get<0>(picker[i])+get<1>(picker[i]);
                    dx-=get<1>(picker[i]);
                }
                else{
                    ans[get<2>(picker[i])]=get<0>(picker[i])+dx;
                    dx=0;
                }
            }
        }
        return;
    }
    for(int i=idx;i<n;++i){
        picker.push_back({v[i].first,v[i].second-v[i].first,i});
        pick(toPick-1,i+1);
        picker.pop_back();
    }
}


int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>n>>p>>e;
    v.resize(n);
    ans.resize(n);
    for(int i=0;i<n;++i){
        cin>>v[i].first>>v[i].second;
    }
    if(n<p) state=false;
    else pick(p,0);
    if(state){
        for(int k:ans) cout<<k<<" ";
    }
    else cout<<-1;
}