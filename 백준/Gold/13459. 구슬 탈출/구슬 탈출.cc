#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;
int n,m;
int dy[4]={-1,1,0,0};
int dx[4]={0,0,-1,1};
pair<int,int> endHole;

string boardToString(vector<string>& board){
    string retStr="";
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            retStr+=board[i][j];
        }
    }
    return retStr;
}
bool canMove(vector<string>& board,pair<int,int> order){
    if(order.first<0||order.first>n||order.second<0||order.second>=m) return false;
    if(board[order.first][order.second]=='#') return false;
    if(board[order.first][order.second]=='B') return false;
    if(board[order.first][order.second]=='R') return false;
    return true;

}

void move(vector<string>& board,pair<int,int> order,int direction,bool isRed){
    if(board.size()==1) return;

    pair<int,int> crnOrder=order;

    bool flag=false;
    char sig=isRed?'R':'B';

    while(true){
        pair<int,int> nxtOrder={
            crnOrder.first+dy[direction],
            crnOrder.second+dx[direction]
        };
        if(canMove(board,nxtOrder)){
            if(board[nxtOrder.first][nxtOrder.second]=='O'){
                board[crnOrder.first][crnOrder.second]='.';
                break;
            }
            else{
                board[nxtOrder.first][nxtOrder.second]=sig;
                board[crnOrder.first][crnOrder.second]='.';
                crnOrder=nxtOrder;
            }
        }
        else break;
    }
    return;
}



vector<string> moveBoard(vector<string>& prevboard,pair<int,int> prevRedOrder,pair<int,int> prevBlueOrder,int direction){
    vector<string> nxtBoard=prevboard;
    if(direction==0){
        if(prevRedOrder.first<prevBlueOrder.first){
            move(nxtBoard,prevRedOrder,direction,true);
            move(nxtBoard,prevBlueOrder,direction,false);
        }
        else{
            move(nxtBoard,prevBlueOrder,direction,false);  
            move(nxtBoard,prevRedOrder,direction,true);
        }
    }
    else if(direction==1){
        if(prevRedOrder.first<prevBlueOrder.first){
            move(nxtBoard,prevBlueOrder,direction,false);
            move(nxtBoard,prevRedOrder,direction,true);
        }
        else{
            move(nxtBoard,prevRedOrder,direction,true);
            move(nxtBoard,prevBlueOrder,direction,false);
        }
    }
    else if(direction==2){
        if(prevRedOrder.second<prevBlueOrder.second){
            move(nxtBoard,prevRedOrder,direction,true);
            move(nxtBoard,prevBlueOrder,direction,false);
        }
        else{
            move(nxtBoard,prevBlueOrder,direction,false);
            move(nxtBoard,prevRedOrder,direction,true);
        }
    }
    else{
        if(prevRedOrder.second<prevBlueOrder.second){
            move(nxtBoard,prevBlueOrder,direction,false);
            move(nxtBoard,prevRedOrder,direction,true);
        }
        else{
            move(nxtBoard,prevRedOrder,direction,true);
            move(nxtBoard,prevBlueOrder,direction,false);
        }
    }
    bool isRedExist=false;
    bool isBLueExist=false;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(nxtBoard[i][j]=='R') isRedExist=true;
            else if(nxtBoard[i][j]=='B') isBLueExist=true;
        }
    }
    if(!isRedExist&&!isBLueExist){
        nxtBoard=vector<string>(1,"fail");
    }
    else if(!isRedExist||!isBLueExist){
        if(!isRedExist){
            nxtBoard=vector<string>(1,"success");
        }
        else nxtBoard=vector<string>(1,"fail");
    }
    return nxtBoard;
}


int main(){
    cin>>n>>m;
    vector<string> v(n);
    
    pair<int,int> redPoint;
    pair<int,int> bluePoint;

    for(int i=0;i<n;++i){
        cin>>v[i];
        for(int j=0;j<m;++j){
            if(v[i][j]=='R'){
                redPoint={i,j};
            }
            else if(v[i][j]=='B'){
                bluePoint={i,j};
            }
            else if(v[i][j]=='O'){
                endHole={i,j};
            }
        }
    }

    unordered_map<string,int> visited;
    priority_queue<tuple<int,vector<string>,pair<pair<int,int>,pair<int,int>>>> q;
    
    string thisIsFirstBoard=boardToString(v);
    visited[thisIsFirstBoard]=0;
    q.push({0,v,{redPoint,bluePoint}});
    int ans=-1;
    while(!q.empty()){
        int crnTime=-get<0>(q.top());
        vector<string> crnBoard=get<1>(q.top());
        pair<int,int> crnRedPoint=get<2>(q.top()).first;
        pair<int,int> crnBluePoint=get<2>(q.top()).second;
        q.pop();

        if(crnTime>=10) break;

        bool flag=false;
        for(int i=0;i<4;++i){
            vector<string> nxtBoard=moveBoard(crnBoard,crnRedPoint,crnBluePoint,i);

            if(nxtBoard.size()==1){
                if(nxtBoard[0]=="fail") continue;
                if(nxtBoard[0]=="success"){
                    flag=true;
                    ans=crnTime+1;
                    break;
                }
            }
            string nxtBoardString=boardToString(nxtBoard);
            if(visited.find(nxtBoardString)==visited.end()){
                visited[nxtBoardString]=crnTime+1;
                pair<int,int> nxtRedPoint;
                pair<int,int> nxtBluePoint;
                for(int i=0;i<n;++i){
                    for(int j=0;j<m;++j){
                        if(nxtBoard[i][j]=='R'){
                            nxtRedPoint={i,j};
                        }
                        else if(nxtBoard[i][j]=='B'){
                            nxtBluePoint={i,j};
                        }
                    }
                }
                q.push({-(crnTime+1),nxtBoard,{nxtRedPoint,nxtBluePoint}});
            }
        }
        if(flag) break;
    }
    if(ans!=-1) cout<<1;
    else cout<<0;
}