#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <tuple>
#include <algorithm>
using namespace std;
int n,m;
vector<string> board;
unordered_map<string,int> visited;
pair<pair<int,int>,pair<int,int>> dongPosition={{-1,-1},{-1,-1}};
int dy[4]={-1,1,0,0};
int dx[4]={0,0,-1,1};

string boardToString(vector<string>& tmpBoard){
    string retStr="";
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            retStr+=tmpBoard[i][j];
        }
    }
    return retStr;
}
bool checkOutBoard(pair<int,int> order){
    int y=order.first;
    int x=order.second;
    if(y<0||y>=n||x<0||x>=m) return true;
    return false;
}
pair<bool,bool> isOutBoard(pair<pair<int,int>,pair<int,int>> tmpOrder){
    return {checkOutBoard(tmpOrder.first),checkOutBoard(tmpOrder.second)};
}

bool checkByoek(pair<int,int> order,vector<string>& tmpBoard){
    int y=order.first;
    int x=order.second;
    if(tmpBoard[y][x]=='#') return true;
    return false;
}

pair<pair<int,int>,pair<int,int>> isByeok(pair<pair<int,int>,pair<int,int>> newOrder,pair<pair<int,int>,pair<int,int>> prevOrder,vector<string>& board){
    pair<int,int> firstOrder=newOrder.first;
    pair<int,int> secondOrder=newOrder.second;
    if(checkByoek(newOrder.first,board)){
        firstOrder=prevOrder.first;
    }
    if(checkByoek(newOrder.second,board)){
        secondOrder=prevOrder.second;
    }
    return {firstOrder,secondOrder};
}

void makeBoardSwap(pair<int,int> newOrder,pair<int,int> prevOrder,vector<string>& board){
    board[newOrder.first][newOrder.second]='o';
    board[prevOrder.first][prevOrder.second]='.';
}

void makeNewBoard(pair<pair<int,int>,pair<int,int>> nxtOrder,pair<pair<int,int>,pair<int,int>> prevOrder,vector<string>& tmpBoard){
    makeBoardSwap(nxtOrder.first,prevOrder.first,tmpBoard);
    makeBoardSwap(nxtOrder.second,prevOrder.second,tmpBoard);
}


int main(){
    cin>>n>>m;
    board.resize(n);
    for(int i=0;i<n;++i){
        string tmp;
        cin>>tmp;
        board[i]=tmp;
    }

    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(board[i][j]=='o'){
                if(dongPosition.first.first==-1){
                    dongPosition.first={i,j};
                }
                else dongPosition.second={i,j};
            }
        }
    }
    string startBoard=boardToString(board);
    priority_queue<tuple<int,vector<string>,pair<pair<int,int>,pair<int,int>>>> q;
    q.push({0,board,dongPosition});
    visited[startBoard]=0;
    int ans=-1;
    while(!q.empty()){
        int crnTime=-get<0>(q.top());
        vector<string> crnBoard=get<1>(q.top());
        pair<pair<int,int>,pair<int,int>> crnPosition=get<2>(q.top());
        q.pop();
        if(crnTime>=10) break;
        bool flag=false;
        for(int i=0;i<4;++i){
            pair<pair<int,int>,pair<int,int>> tmpPosition=crnPosition;
            tmpPosition.first={tmpPosition.first.first+dy[i],tmpPosition.first.second+dx[i]};
            tmpPosition.second={tmpPosition.second.first+dy[i],tmpPosition.second.second+dx[i]};
            pair<bool,bool> pandanOutBoard=isOutBoard(tmpPosition);
            if(pandanOutBoard.first&&pandanOutBoard.second) continue;
            if(pandanOutBoard.first||pandanOutBoard.second){
                flag=true;
                break;
            }
            vector<string> tmpCrnBoard=crnBoard;
            tmpPosition=isByeok(tmpPosition,crnPosition,crnBoard);
            makeNewBoard(tmpPosition,crnPosition,tmpCrnBoard);
            string tmpBoardString=boardToString(tmpCrnBoard);
            if(visited.find(tmpBoardString)==visited.end()){
                visited[tmpBoardString]=crnTime+1;
                q.push({-(crnTime+1),tmpCrnBoard,tmpPosition});
            }
        }
        if(flag){
            ans=crnTime+1;
            break;
        }
    }
    cout<<ans;
}