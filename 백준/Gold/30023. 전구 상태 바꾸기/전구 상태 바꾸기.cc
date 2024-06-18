#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    string a;
    cin>>n>>a;
    vector<int> tmpA(n);
    vector<int> tmpB(n);
    vector<int> tmpC(n);
    for(int i=0;i<n;++i){
        if(a[i]=='R') tmpA[i]=tmpB[i]=tmpC[i]=0;
        else if(a[i]=='G') tmpA[i]=tmpB[i]=tmpC[i]=1;
        else tmpA[i]=tmpB[i]=tmpC[i]=2;
    }
    int ansA=0,ansB=0,ansC=0;
    for(int i=0;i<n-2;++i){
        if(tmpA[i]==1){
            tmpA[i+1]=(tmpA[i+1]+2)%3;
            tmpA[i+2]=(tmpA[i+2]+2)%3;
            ansA+=2;
        }
        else if(tmpA[i]==2){
            tmpA[i+1]=(tmpA[i+1]+1)%3;
            tmpA[i+2]=(tmpA[i+2]+1)%3;
            ansA+=1;
        }

        if(tmpB[i]==2){
            tmpB[i+1]=(tmpB[i+1]+2)%3;
            tmpB[i+2]=(tmpB[i+2]+2)%3;
            ansB+=2;
        }
        else if(tmpB[i]==0){
            tmpB[i+1]=(tmpB[i+1]+1)%3;
            tmpB[i+2]=(tmpB[i+2]+1)%3;
            ansB+=1;
        }

        if(tmpC[i]==0){
            tmpC[i+1]=(tmpC[i+1]+2)%3;
            tmpC[i+2]=(tmpC[i+2]+2)%3;
            ansC+=2;
        }
        else if(tmpC[i]==1){
            tmpC[i+1]=(tmpC[i+1]+1)%3;
            tmpC[i+2]=(tmpC[i+2]+1)%3;
            ansC+=1;            
        }
    }
    if(tmpA[n-1]!=0||tmpA[n-2]!=0) ansA=987654321;
    if(tmpB[n-1]!=1||tmpB[n-2]!=1) ansB=987654321;
    if(tmpC[n-1]!=2||tmpC[n-2]!=2) ansC=987654321;
    int ans=min({ansA,ansB,ansC});
    if(ans==987654321) ans=-1;
    cout<<ans;
}