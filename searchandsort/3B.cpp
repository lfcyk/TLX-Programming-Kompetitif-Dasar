#include<iostream>
using namespace std;

int N,M,K,board[102][102],boardkemenarikan[102][102];

void readBoard(){
    cin >> N >> M >> K;

    for(int i=0;i<=N+1;i++){
        for(int j=0;j<=M+1;j++){
            if((i==0)||(j==0)||(j==M+1)||(i==N+1)){
                board[i][j] = 1;
            } else{
                cin >> board[i][j];
            }
        }
    }
}

void countKemenarikan(){
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            boardkemenarikan[i][j]=board[i-1][j]*board[i][j-1]*board[i+1][j]*board[i][j+1];
        }
    }
}

bool carikemenarikan(){
    for(int i=1;i<=M;i++){
        for(int j=1;j<=N;j++){
            if(boardkemenarikan[j][i]==K){
                cout << j << " " << i;
                return true;
            }
        }
    }
    return false;
}

void writeBoard(){
    for(int i=0;i<=N+1;i++){
        for(int j=0;j<=M+1;j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

}

void writeKemenarikan(){
    for(int i=0;i<=N+1;i++){
        for(int j=0;j<=M+1;j++){
            cout << boardkemenarikan[i][j] << " ";
        }
        cout << endl;
    }

}
int main(){
    readBoard();
    //writeBoard();
    countKemenarikan();
    //writeKemenarikan();
    if(!carikemenarikan()){
        cout << "0 0";
    }
}