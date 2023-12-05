#include <string>
#include <vector>
#include <set>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    multiset<int> s;
    for(int i=0;i<operations.size();++i){
        
        if(operations[i][0]=='I'){
            int val=0;
            if(operations[i][2]=='-'){
                for(int j=3;j<operations[i].size();++j){
                    val*=10;
                    val+=operations[i][j]-'0';
                }
                val*=-1;
            }else{
                for(int j=2;j<operations[i].size();++j){
                    val*=10;
                    val+=operations[i][j]-'0';
                }
            }
            s.insert(val);
        }else{
            if(operations[i][2]=='1'){
                if(!s.empty()){
                    auto it=s.end();
                    --it;
                    s.erase(it); 
                }
            }else{
                if(!s.empty()){
                    auto it=s.begin();
                    s.erase(it);                   
                }
            }
        }
    }
    if(s.empty()){
        answer.push_back(0);
        answer.push_back(0);
    }else{
        int tmp=*s.rbegin();
        answer.push_back(tmp);
        tmp=*s.begin();
        answer.push_back(tmp);
    }
    return answer;
}