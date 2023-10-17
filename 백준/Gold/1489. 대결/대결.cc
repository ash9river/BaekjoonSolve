#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
vector<int> a;
vector<int> b;
int n;//23%시간초과
int cache[50][50][50];
int match(int ptrA,int frontBPtr,int backBptr){
    if(ptrA>=n||frontBPtr>=n||backBptr<0) return 0;
    if(frontBPtr>backBptr) return 0;
    int& ret=cache[ptrA][frontBPtr][backBptr];
    if(ret!=-1) return ret;
    if(a[ptrA]>b[frontBPtr]){
        return ret=2+match(ptrA+1,frontBPtr+1,backBptr);
    }
    else if(a[ptrA]<b[frontBPtr]){
        return ret=match(ptrA+1,frontBPtr,backBptr-1);
    }
    int firstResult=1+match(ptrA+1,frontBPtr+1,backBptr);
    int secondResult=match(ptrA+1,frontBPtr,backBptr);
    return ret=max(firstResult,secondResult);
}

void init(){// ptrA,frontBPtr,backBptr
    memset(cache,-1,sizeof(cache));
    cout<<match(0,0,n-1);
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>n;
    a.resize(n);
    b.resize(n);
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    for(int i=0;i<n;++i){
        cin>>b[i];
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    init();
}