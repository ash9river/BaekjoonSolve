#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>n;
    priority_queue<int,vector<int>,greater<>> pq;
    int u,count=0;
    for(int i=0;i<n;i++){
        cin>>u;
        pq.push(u);
    }
    if(n!=1){
        while(!pq.empty()){
            if(pq.size()==3){
                int a=pq.top();
                pq.pop();
                int b=pq.top();
                pq.pop();
                int c=pq.top();
                pq.pop();
                count+=2*a+2*b+c;
                break;
            }
            else if(pq.size()==2){
                int a=pq.top();
                pq.pop();
                int b=pq.top();
                pq.pop();
                count+=a+b;
            }
            else{
                int a=pq.top();
                pq.pop();
                int b=pq.top();
                pq.pop();
                count+=a+b;
                pq.push(a+b);

            }
        }
    }
    cout<<count;
}