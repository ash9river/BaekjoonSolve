#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;//3퍼틀
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n;
    cin>>n;
    vector<pair<int,ll>> s; //set,gaesu
    ll a;
    for(int i=0;i<n;++i){
        cin>>a;
        int tmp=0;
        while(a>0){
            int p=a%10;
            tmp|=(1<<p);
            a/=10;
        }
        bool state=false;
        for(int i=0;i<s.size();++i){
            int t=tmp^s[i].first;
            if(t==0){
                state=true;
                ++s[i].second;
                break;
            }
        }
        if(!state){
            s.push_back({tmp,1});
        }
    }
    sort(s.begin(),s.end(),greater<>());
    ll result=0;
    int sSize=s.size();
    for(int i=0;i<sSize-1;++i){

        result+=(s[i].second*(s[i].second-1))/2;
        
        for(int j=i+1;j<sSize;++j){
            int t=s[i].first&s[j].first;
            if(t!=0){
                result+=s[i].second*s[j].second;
            }
        }
    }
    result+=(s[sSize-1].second*(s[sSize-1].second-1))/2;
    cout<<result;
}