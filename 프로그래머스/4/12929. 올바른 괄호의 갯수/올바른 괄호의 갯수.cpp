#include <string>
#include <vector>

using namespace std; // Catalan: 2nCn/n+1
long long C[30][30];
int solution(int n) {
    int answer = 0;
    for(int i=1;i<=2*n;++i){
        for(int j=0;j<=i;++j){
            if(j==0||j==i) C[i][j]=1;
            else C[i][j]=C[i-1][j-1]+C[i-1][j];
        }
    }
    answer=C[2*n][n]/(n+1);
    return answer;
}