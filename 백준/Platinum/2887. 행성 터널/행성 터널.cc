#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
vector<pair<tuple<int,int,int>,int>> order;
vector<pair<int,pair<int,int>>> v;
int parent[100001];
int n;
int findParent(int vertex){
    if(parent[vertex]!=vertex) parent[vertex]=findParent(parent[vertex]);
    return parent[vertex];
}
bool cmp1(const pair<tuple<int,int,int>,int>& v1,const pair<tuple<int,int,int>,int>& v2){
    return get<1>(v1.first)<get<1>(v2.first);
}
bool cmp2(const pair<tuple<int,int,int>,int>& v1,const pair<tuple<int,int,int>,int>& v2){
    return get<2>(v1.first)<get<2>(v2.first);
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>n;
    int x,y,z;
    order.resize(n);
    for(int i=0;i<n;++i){
        cin>>get<0>(order[i].first)>>get<1>(order[i].first)>>get<2>(order[i].first);
        order[i].second=i;
        parent[i]=i;
    }
    sort(order.begin(),order.end());
    for(int i=0;i<n-1;++i){
        int x=abs(get<0>(order[i].first)-get<0>(order[i+1].first));
        int y=abs(get<1>(order[i].first)-get<1>(order[i+1].first));
        int z=abs(get<2>(order[i].first)-get<2>(order[i+1].first));
        int minA=min({x,y,z});
        v.push_back({minA,{order[i].second,order[i+1].second}});
    }
    sort(order.begin(),order.end(),cmp1);
    for(int i=0;i<n-1;++i){
        int x=abs(get<0>(order[i].first)-get<0>(order[i+1].first));
        int y=abs(get<1>(order[i].first)-get<1>(order[i+1].first));
        int z=abs(get<2>(order[i].first)-get<2>(order[i+1].first));
        int minA=min({x,y,z});
        v.push_back({minA,{order[i].second,order[i+1].second}});
    }
    sort(order.begin(),order.end(),cmp2);
    for(int i=0;i<n-1;++i){
        int x=abs(get<0>(order[i].first)-get<0>(order[i+1].first));
        int y=abs(get<1>(order[i].first)-get<1>(order[i+1].first));
        int z=abs(get<2>(order[i].first)-get<2>(order[i+1].first));
        int minA=min({x,y,z});
        v.push_back({minA,{order[i].second,order[i+1].second}});
    }
    sort(v.begin(),v.end());
    int vSize=v.size();
    int rslt=0;
    for(int i=0;i<vSize;++i){
        int parentA=findParent(v[i].second.first);
        int parentB=findParent(v[i].second.second);
        if(parentA!=parentB){
            parent[parentA]=parentB;
            rslt+=v[i].first;
        }
    }
    cout<<rslt;
}
