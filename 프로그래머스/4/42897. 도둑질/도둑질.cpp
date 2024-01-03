#include <string>
#include <vector>
#define ll long long
using namespace std;
int solution(vector<int> money) {
    ll answer=0;
    int mSize=money.size();
    vector<ll> dp(mSize+1,0);
    dp[0]=money[0];
    dp[1]=money[0];
    for(int i=2;i<mSize-1;++i){
        dp[i]=max(dp[i-2]+money[i],dp[i-1]);
    }
    answer=dp[mSize-2];
    dp[0]=0;
    dp[1]=money[1];
    for(int i=2;i<mSize;++i){
        dp[i]=max(dp[i-2]+money[i],dp[i-1]);
    }
    answer=max(answer,dp[mSize-1]);
    return answer;
}