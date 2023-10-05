#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;//34%틀
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> v(m);
    for(int i=0;i<m;++i){
        cin>>v[i].first>>v[i].second;
    }
    sort(v.begin(),v.end());
    bool state=true;
    for(int i=0;i<m-1;++i){
        if(v[i].first==v[i+1].first){
            if(v[i].second!=v[i+1].second){
                state=false;
                break;
            }
        }
        if(v[i].first>=n){
            state=false;
            break;
        }
    }
    if(v[m-1].first>=n) state=false;
    if(!state) cout<<0;
    else{
        vector<vector<int>> dp(31,vector<int>(31,0));
        int ptr=v[0].first;
        int k=0;
        dp[0][0]=1;
        if(ptr==0){
            while(k<m){
                ++k;
                if(v[k].first!=0){
                    ptr=v[k].first;
                    break;
                }
            }
        }
        for(int i=1;i<n;++i){
            dp[i][0]=dp[i-1][0];
            for(int j=1;j<i;++j){
                dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
            }
            dp[i][i]=dp[i-1][i-1];
            if(i==ptr){
                for(int j=0;j<=i;++j){
                    if(j!=v[k].second) dp[i][j]=0;
                }
                while(k<m){
                    if(v[k].first==ptr) ++k;
                    else{
                        ptr=v[k].first;
                        break;
                    }
                }
            }
        }
        long long sum=0;
        for(int i=0;i<=n;++i){
            sum+=dp[n-1][i];
        }
/*         for(int i=0;i<n;++i){
            for(int j=0;j<=i;++j){
                cout<<dp[i][j]<<" ";
            }
            cout<<"\n";
        } */
        cout<<sum;
    }
}