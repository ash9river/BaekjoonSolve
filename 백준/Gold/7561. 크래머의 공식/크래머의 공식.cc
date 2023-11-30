#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>
#define ll long long
#define EPSILON 0.0005
using namespace std;//25퍼틀
vector<vector<ll>> a(3,vector<ll>(3));
vector<ll> b(3);
ll det(ll a11,ll a12,ll a21,ll a22){
    return a11*a22-a12*a21;
}
ll det(ll a11,ll a12,ll a13,ll a21,ll a22,ll a23,ll a31,ll a32,ll a33){
    return a11*det(a22,a23,a32,a33)
    -a12*det(a21,a23,a31,a33)
    +a13*det(a21,a22,a31,a32);
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin>>t;
    cout<<fixed<<setprecision(3);
    while(t-->0){
        for(int i=0;i<3;++i){
            for(int j=0;j<3;++j){
                cin>>a[i][j];
            }
            cin>>b[i];
        }
        ll ans[4]={
            det(b[0],a[0][1],a[0][2],b[1],a[1][1],a[1][2],b[2],a[2][1],a[2][2]),
            det(a[0][0],b[0],a[0][2],a[1][0],b[1],a[1][2],a[2][0],b[2],a[2][2]),
            det(a[0][0],a[0][1],b[0],a[1][0],a[1][1],b[1],a[2][0],a[2][1],b[2]),
            det(a[0][0],a[0][1],a[0][2],a[1][0],a[1][1],a[1][2],a[2][0],a[2][1],a[2][2])
        };
        for(int i=0;i<3;++i) cout<<ans[i]<<" ";
        cout<<ans[3]<<'\n';
        if(ans[3]==0){
            cout<<"No unique solution";
        }
        else{
            cout<<"Unique solution: ";
            for(int i=0;i<2;++i){
                double k=ans[i]/(double)ans[3];
                k=round(k*1000)/1000;
                if(k>-EPSILON&&k<EPSILON) k=0.0;
                cout<<k<<" ";
            }
            double k=ans[2]/(double)ans[3];
            k=round(k*1000)/1000;   
            if(k>-EPSILON&&k<EPSILON) k=0.0;
            cout<<k;
        }
        cout<<"\n\n";
    }
}