#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define ll long long
using namespace std;//23796
ll board[8][8];
bool visitied[8][8];
string command;
void boardUp(){
    for(int j=0;j<8;++j){
        for(int i=0;i<8;++i){
            if(board[i][j]!=0){
                for(int k=i-1;k>=0;--k){
                    if(board[k][j]!=0){
                        if(board[k][j]==board[k+1][j]&&!visitied[k][j]){
                            board[k][j]+=board[k+1][j];
                            board[k+1][j]=0;
                            visitied[k][j]=true;
                        }
                        break;
                    }
                    else{
                        board[k][j]=board[k+1][j];
                        board[k+1][j]=0;
                    }
                }
            }
        }
    }
}
void boardDown(){
    for(int j=0;j<8;++j){
        for(int i=7;i>=0;--i){
            if(board[i][j]!=0){
                for(int k=i+1;k<=7;++k){
                    if(board[k][j]!=0){
                        if(board[k][j]==board[k-1][j]&&!visitied[k][j]){
                            board[k][j]+=board[k-1][j];
                            board[k-1][j]=0;
                            visitied[k][j]=true;
                        }
                        break;
                    }
                    else{
                        board[k][j]=board[k-1][j];
                        board[k-1][j]=0;
                    }
                }
            }
        }
    }
}
void boardLeft(){
    for(int i=0;i<8;++i){
        for(int j=0;j<8;++j){
            if(board[i][j]!=0){
                for(int k=j-1;k>=0;--k){
                    if(board[i][k]!=0){
                        if(board[i][k]==board[i][k+1]&&!visitied[i][k]){
                            board[i][k]+=board[i][k+1];
                            board[i][k+1]=0;
                            visitied[i][k]=true;
                        }
                        break;
                    }
                    else{
                        board[i][k]=board[i][k+1];
                        board[i][k+1]=0;
                    }
                }
            }
        }
    }
}
void boardRight(){
    for(int i=0;i<8;++i){
        for(int j=7;j>=0;--j){
            if(board[i][j]!=0){
                for(int k=j+1;k<8;++k){
                    if(board[i][k]!=0){
                        if(board[i][k]==board[i][k-1]&&!visitied[i][k]){
                            board[i][k]+=board[i][k-1];
                            board[i][k-1]=0;
                            visitied[i][k]=true;
                        }
                        break;
                    }
                    else{
                        board[i][k]=board[i][k-1];
                        board[i][k-1]=0;
                    }
                }
            }
        }
    }
}
void makeBoard(){
    if(command=="U") boardUp();
    else if(command=="L") boardLeft();
    else if(command=="R") boardRight();
    else boardDown();
}
void printBoard(){
    for(int i=0;i<8;++i){
        for(int j=0;j<7;++j){
            cout<<board[i][j]<<" ";
        }
        cout<<board[i][7]<<"\n";
    }
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    for(int i=0;i<8;++i){
        for(int j=0;j<8;++j){
            cin>>board[i][j];
        }
    }
    cin>>command;
    makeBoard();
    printBoard();
}