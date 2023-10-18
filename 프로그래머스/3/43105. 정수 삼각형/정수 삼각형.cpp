#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int cache[500][500];
    cache[0][0]=triangle[0][0];
    int triSize=triangle.size();
    for(int i=0;i<=triSize-1;++i){
        cache[triSize-1][i]=triangle[triSize-1][i];
    }
    for(int i=triSize-2;i>=0;--i){
        for(int j=0;j<=i;++j){
            cache[i][j]=triangle[i][j]+max(cache[i+1][j],cache[i+1][j+1]);
        }
    }
    answer=cache[0][0];
    return answer;
}