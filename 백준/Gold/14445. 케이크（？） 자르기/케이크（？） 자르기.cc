#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    ll n;
    cin>>n;
    if(n==1) cout<<0;
    else if(n&(1<<0)) cout<<(n/2)+1;
    else cout<<n/2;
}