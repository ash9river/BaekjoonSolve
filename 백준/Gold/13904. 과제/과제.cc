#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std; //바로틀 
priority_queue<pair<int,int>> q;
vector<int> table(1001);
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    int a,b;
    for(int i=0;i<n;++i){
        cin>>a>>b;
        q.push({b,a});
    }
    while(!q.empty()){
        int jum=q.top().first;
        int day=q.top().second;
        q.pop();

        for(int i=day;i>0;--i){
            if(table[i]==0){
                table[i]=jum;
                break;
            }
            else continue;
        }
    }
    int res=0;
    for(int i=1;i<=1000;++i){
        res+=table[i];
    }
    cout<<res;

}