#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<bool> prime(10000001,true);
void makePrime(){
    prime[0]=prime[1]=false;
    for(int i=2;i*i<=1000000;++i){
        if(prime[i]){
            for(int j=i*i;j<=1000000;j+=i){
                prime[j]=false;
            }
        }
    }
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    makePrime();
    int n;
    while(true){
        cin>>n;
        if(n==0) break;
        for(int i=3;i<n/2+1;++i){
            if(prime[i]&&prime[n-i]){
                cout<<n<<" = "<<i<<" + "<<n-i<<"\n";
                break;
            }
        }
    }
}