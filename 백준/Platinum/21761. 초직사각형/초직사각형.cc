#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define ull unsigned long long
using namespace std;
vector<ull> s;
bool cmp(pair<ull,int>& prev,pair<ull,int>& nxt){
    return (prev.first+s[prev.second])*s[nxt.second]>(nxt.first+s[nxt.second])*s[prev.second];
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    ull n,k,a,b,c,d;
    cin>>n>>k>>a>>b>>c>>d;
    vector<priority_queue<ull>> v(4,priority_queue<ull>());
    for(int i=0;i<n;++i){
        char t;
        ull u;
        cin>>t>>u;
        v[t-'A'].push(u);
    }
    s.push_back(a);
    s.push_back(b);
    s.push_back(c);
    s.push_back(d);
    for(int i=0;i<k;++i){
        ull maxVal=1;
        vector<pair<ull,int>> tmpS;
        for(int j=0;j<4;++j){
            if(v[j].empty()) continue;
            tmpS.push_back({v[j].top(),j});
        }
        sort(tmpS.begin(),tmpS.end(),cmp);
        cout<<(char)(tmpS[0].second+'A')<<" "<<tmpS[0].first<<"\n";
        v[tmpS[0].second].pop();
        s[tmpS[0].second]+=tmpS[0].first;      
    }
   
}