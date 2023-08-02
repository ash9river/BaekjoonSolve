#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int ptr=1;
int n;
vector<int> prime(500001,0);
void erato(){
    prime[1]=ptr++;
    int i;
    for(i=2;i*i<=n;++i){
        if(prime[i]==0){
            prime[i]=ptr;
            for(int j=i*i;j<=n;j+=i){
                if(prime[j]==0) prime[j]=ptr;
            }
            ++ptr;
        }
    }
    for(int j=i;j<=n;++j){
        if(prime[j]==0) prime[j]=ptr++;
    }
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>n;
    erato();
    cout<<ptr-1<<'\n';
    for(int i=1;i<=n;++i){
        cout<<prime[i]<<" ";
    }
}