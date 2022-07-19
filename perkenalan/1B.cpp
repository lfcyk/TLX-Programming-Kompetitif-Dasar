#include<iostream>
using namespace std;

int R,C;
char board[20][8];
int lowestRowGone;

void readBoard(){
    cin >> R >> C;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin >> board[i][j];
        }
    }
}

void writeBoard(){
    cout << '\n';
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cout << board[i][j];
        }
        cout << '\n';
    }
}

int isRowGone(int r){
    for(int j=0;j<C;j++){
        if(board[r][j]=='0'){
            return false;
        }
    }
    return true;
}

void clearRow(int r){
    for(int j=0;j<C;j++){
        board[r][j]='0';
    }
}

void collapse(){
    for(int i=0;i<C;i++){
        int onesAboveLantai=0;
        int lantai=R-1;
        for(int j=R-1;j>lowestRowGone;j--){
            if(board[j][i]=='1'){
                lantai=j-1;
            }
        }
        for(int j=lowestRowGone;j>=0;j--){
            if(board[j][i]=='1'){
                onesAboveLantai+=1;
                board[j][i]='0';
            }
        }
        while(onesAboveLantai>0){
            board[lantai][i]='1';
            lantai--;
            onesAboveLantai--;
        }
    }
}

int main(){
    bool isAnyRowGone;
    readBoard();
    do{
        isAnyRowGone=false;
        for(int i=0;i<R;i++){
            if(isRowGone(i)){
                clearRow(i);
                isAnyRowGone=1;
                lowestRowGone=i;
            }
        }
        collapse();
    }while(isAnyRowGone);
    writeBoard();
}