#include <iostream>
#include <map>
#include <algorithm>
#define ull unsigned long long
using namespace std;
ull mod=1000000007;
map<ull,ull> f;
ull fibo(ull n){
    if(n==0) return 0;
    if(n==1) return 1;
    if(n==2) return 1;
    if(f.count(n)>0) return f[n];
    if(n%2==0){
        ull m=n/2;
        ull a=fibo(m-1),b=fibo(m);
        return f[n]=((((ull)2)*a+b)*b)%mod;
    }
    ull a=fibo((n+1)/2),b=fibo((n-1)/2);
    return f[n]=(a*a+b*b)%mod;
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    ull n;
    cin>>n;
    cout<<fibo(n);
}