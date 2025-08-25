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
    vector<ull> s;
    s.push_back(a);
    s.push_back(b);
    s.push_back(c);
    s.push_back(d);
    for(int i=0;i<k;++i){
        ull maxVal=1;
        vector<ull> tmpS(4);
        for(int j=0;j<4;++j){
            if(v[j].empty()) continue;
            ull tmpMaxVal=v[j].top()+s[j];
            for(int k=0;k<4;++k){
                if(k==j) continue;
                tmpMaxVal*=s[k];
            }
            tmpS[j]=tmpMaxVal;
            maxVal=max(maxVal,tmpS[j]);
        }
        for(int j=0;j<4;++j){
            if(v[j].empty()) continue;
            if(maxVal==tmpS[j]){
                cout<<(char)(j+'A')<<" "<<v[j].top()<<'\n';
                s[j]+=v[j].top();
                v[j].pop();
                break;
            }
        }
    }
   
}