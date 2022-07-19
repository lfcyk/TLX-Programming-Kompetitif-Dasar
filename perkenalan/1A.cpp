#include<iostream>
#include<string>
using namespace std;

int main(){
    int T,N,M,idx;
    int cnt;

    cin >> T;
    
    int mark[81][3];
    string P[81],S;

    for(int i=0;i<T;i++){
        cnt=0;

        cin >> N >> M;
        cin >> S;
        for(int j=0;j<N;j++){
            cin >> P[j] >> mark[j][0] >> mark[j][1] >> mark[j][2];
            if(P[j]==S){
                idx = j;
            }
        }

        for(int j=0;j<N;j++){
            if(mark[idx][2] < mark[j][2]){
                cnt++;
            } else if((mark[idx][2] == mark[j][2]) && (mark[idx][1] < mark[j][1])){
                cnt++;
            } else if((mark[idx][2] == mark[j][2]) && (mark[idx][1] == mark[j][1]) && (mark[idx][0] < mark[j][0])){
                cnt++;
            }
        }

        if(cnt < M){
            cout << "YA" << '\n';
        } else {
            cout << "TIDAK" << '\n';
        }
    }

    
}