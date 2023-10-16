#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;//13%틀
vector<vector<int>> table;
vector<int> v(4);
vector<int> picker;
vector<int> minTable;
int n,minCost=987654321;
bool pan(string a,string b){
    if(a<b) return true;
    return false;

}
void pick(int gae,int start){
    if(gae==0){
        vector<int> sum(5,0);
        int pSize=picker.size();
        for(int i=0;i<pSize;++i){
            for(int j=0;j<5;++j){
                sum[j]+=table[picker[i]][j];
            }
        }
        bool state=true;
        int rslt=sum[4];
        for(int i=0;i<4;++i){
            if(v[i]>sum[i]){
                state=false;
                break;
            }
        }
        if(state){
            if(minCost>rslt){
                minCost=rslt;
                minTable=picker;
            }
            else if(minCost==rslt){
                int tSize=minTable.size();
                string a="",b="";
                for(int i=0;i<tSize;++i){
                    a+=(minTable[i]+'0');
                }
                for(int i=0;i<pSize;++i){
                    b+=(picker[i]+'0');
                }
                if(!pan(a,b)){
                    minTable=picker;
                }
            }
        }
        return;
    }
    for(int i=start;i<=n;++i){
        picker.push_back(i);
        pick(gae-1,i+1);
        picker.pop_back();
    }
    return;
}
void init(){
    for(int i=1;i<=n;++i){
        pick(i,1);
    }
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=0;i<4;++i){
        cin>>v[i];
    }
    table.resize(n+1,vector<int>(5,0));
    for(int i=1;i<=n;++i){
        for(int j=0;j<5;++j){
            cin>>table[i][j];
        }
    }
    init();
    if(minCost==987654321) cout<<-1;
    else{
        cout<<minCost<<"\n";
        for(int k:minTable) cout<<k<<" ";
    }
}