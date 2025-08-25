#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define ull unsigned long long
using namespace std;
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
    vector<ull> s(4);
    s.push_back(a);
    s.push_back(b);
    s.push_back(c);
    s.push_back(d);
    for(int i=0;i<k;++i){
        double tmpRatio=-1;
        int tmpIdx=0;
        vector<ull> tmpS(4);
        for(int j=0;j<4;++j){
            if(v[j].empty()) continue;
            tmpRatio=max((double)v[j].top()/(double)s[j],tmpRatio);
            tmpIdx=j;
        }
        for(int j=0;j<4;++j){
            if(v[j].empty()) continue;
            if(tmpIdx==j){
                cout<<(char)(j+'A')<<" "<<v[j].top()<<'\n';
                s[j]+=v[j].top();
                v[j].pop();
                break;
            }
        }
    }
   
}