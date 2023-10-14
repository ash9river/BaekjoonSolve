컴파일러마다 초기화가 다르다는걸 몰라서 헤맸음.
배열 선언 후 초기화를 {false,}일캐하면 백준컴파일러는 undefined로 받아들이는것같다.

```

#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <algorithm>
using namespace std; //11%틀
int m,n,o,p,q,r,s,t,u,v,w;
int ansTime;
int dM[22]={1,-1,0,};
int dN[22]={0,0,1,-1,0,};
int dO[22]={0,0,0,0,1,-1,0,};
int dP[22]={0,0,0,0,0,0,1,-1,0};
int dQ[22]={0,0,0,0,0,0,0,0,1,-1,0,};
int dR[22]={0,0,0,0,0,0,0,0,0,0,1,-1,0,};
int dS[22]={0,0,0,0,0,0,0,0,0,0,0,0,1,-1,0,};
int dT[22]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,-1,0,};
int dU[22]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,-1,0,};
int dV[22]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,-1,0,};
int dW[22]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,-1};
bool set(int nm,int nn,int no,int np,int nq,int nr,int ns,int nt,int nu,int nv,int nw){
    if(nm<0||nn<0||no<0||np<0||nq<0||nr<0||ns<0||nt<0||nu<0||nv<0||nw<0) return false;
    if(nm>=m||nn>=n||no>=o||np>=p||nq>=q||nr>=r||ns>=s||nt>=t||nu>=u||nv>=v||nw>=w) return false;
    return true;
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>m>>n>>o>>p>>q>>r>>s>>t>>u>>v>>w;
    int board[m][n][o][p][q][r][s][t][u][v][w];
    bool visited[m][n][o][p][q][r][s][t][u][v][w];
    queue<tuple<int,tuple<tuple<int,int,int>,tuple<int,int,int>,pair<int,int>>,tuple<int,int,int>>> queOfTomato;
    for(int i11=0;i11<w;++i11){
        for(int i10=0;i10<v;++i10){
            for(int i9=0;i9<u;++i9){
                for(int i8=0;i8<t;++i8){
                    for(int i7=0;i7<s;++i7){
                        for(int i6=0;i6<r;++i6){
                            for(int i5=0;i5<q;++i5){
                                for(int i4=0;i4<p;++i4){
                                    for(int i3=0;i3<o;++i3){
                                        for(int i2=0;i2<n;++i2){
                                            for(int i1=0;i1<m;++i1){
                                                visited[i1][i2][i3][i4][i5][i6][i7][i8][i9][i10][i11]=false;
                                                cin>>board[i1][i2][i3][i4][i5][i6][i7][i8][i9][i10][i11];
                                                if(board[i1][i2][i3][i4][i5][i6][i7][i8][i9][i10][i11]==1){
                                                    queOfTomato.push({0,{{i1,i2,i3},{i4,i5,i6},{i7,i8}},{i9,i10,i11}});
                                                    visited[i1][i2][i3][i4][i5][i6][i7][i8][i9][i10][i11]=true;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    while(!queOfTomato.empty()){
        int time=get<0>(queOfTomato.front());
        int crnM=get<0>(get<0>(get<1>(queOfTomato.front())));
        int crnN=get<1>(get<0>(get<1>(queOfTomato.front())));
        int crnO=get<2>(get<0>(get<1>(queOfTomato.front())));
        int crnP=get<0>(get<1>(get<1>(queOfTomato.front())));
        int crnQ=get<1>(get<1>(get<1>(queOfTomato.front())));
        int crnR=get<2>(get<1>(get<1>(queOfTomato.front())));
        int crnS=get<2>(get<1>(queOfTomato.front())).first;
        int crnT=get<2>(get<1>(queOfTomato.front())).second;
        int crnU=get<0>(get<2>(queOfTomato.front()));
        int crnV=get<1>(get<2>(queOfTomato.front()));
        int crnW=get<2>(get<2>(queOfTomato.front()));
        queOfTomato.pop();
        for(int i=0;i<22;++i){
            int nxtM=crnM+dM[i];
            int nxtN=crnN+dN[i];
            int nxtO=crnO+dO[i];
            int nxtP=crnP+dP[i];
            int nxtQ=crnQ+dQ[i];
            int nxtR=crnR+dR[i];
            int nxtS=crnS+dS[i];
            int nxtT=crnT+dT[i];
            int nxtU=crnU+dU[i];
            int nxtV=crnV+dV[i];
            int nxtW=crnW+dW[i];
            if(set(nxtM,nxtN,nxtO,nxtP,nxtQ,nxtR,nxtS,nxtT,nxtU,nxtV,nxtW)){
                if(!visited[nxtM][nxtN][nxtO][nxtP][nxtQ][nxtR][nxtS][nxtT][nxtU][nxtV][nxtW]){
                    if(board[nxtM][nxtN][nxtO][nxtP][nxtQ][nxtR][nxtS][nxtT][nxtU][nxtV][nxtW]==0){
                        board[nxtM][nxtN][nxtO][nxtP][nxtQ][nxtR][nxtS][nxtT][nxtU][nxtV][nxtW]=1;
                        visited[nxtM][nxtN][nxtO][nxtP][nxtQ][nxtR][nxtS][nxtT][nxtU][nxtV][nxtW]=true;
                        queOfTomato.push({time+1,{{nxtM,nxtN,nxtO},{nxtP,nxtQ,nxtR},{nxtS,nxtT}},{nxtU,nxtV,nxtW}});
                    }
                }
            }
        }
        ansTime=time;
    }
    bool state=true;
    for(int i11=0;i11<w;++i11){
        for(int i10=0;i10<v;++i10){
            for(int i9=0;i9<u;++i9){
                for(int i8=0;i8<t;++i8){
                    for(int i7=0;i7<s;++i7){
                        for(int i6=0;i6<r;++i6){
                            for(int i5=0;i5<q;++i5){
                                for(int i4=0;i4<p;++i4){
                                    for(int i3=0;i3<o;++i3){
                                        for(int i2=0;i2<n;++i2){
                                            for(int i1=0;i1<m;++i1){
                                                if(!state) break;
                                                if(board[i1][i2][i3][i4][i5][i6][i7][i8][i9][i10][i11]==0){
                                                    state=false;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if(!state) cout<<-1;
    else cout<<ansTime;
}
```
