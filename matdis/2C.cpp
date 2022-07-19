#include<iostream>
using namespace std;

int main(){
    int N,D[21];
    int biggest=0;
    bool kpk=false;

    cin >> N;
    for(int i=0;i<N;i++){
        cin >> D[i];
        if(D[i]>biggest){
            biggest=D[i];
        }
    }

    int j=biggest;
    while(!kpk){
        int i;
        for(i=0;i<N;i++){
            if(j%D[i]!=0){
                j+=biggest;
                break;
            }
        }
        if(i==N){
            kpk=true;
        }        
    }

    cout << j;
}