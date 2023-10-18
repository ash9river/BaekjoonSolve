#include <string>
#include <vector>
#define ll long long
#define mod 1000000007
using namespace std;
 bool mul[101][101];
ll dp[101][101];
int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
   
    for(int i=0;i<puddles.size();++i){
        mul[puddles[i][1]-1][puddles[i][0]-1]=true;
    }
    dp[n][m-1]=1;
    for(int i=n-1;i>=0;--i){
        for(int j=m-1;j>=0;--j){
            if(!mul[i][j]){
                dp[i][j]=(dp[i+1][j]+dp[i][j+1])%mod;
            }
        }
    }
    answer=dp[0][0];
    return answer;
}