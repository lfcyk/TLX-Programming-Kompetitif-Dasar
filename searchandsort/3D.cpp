#include<iostream>
using namespace std;
int N,Q,bb[100000],batas[2];

void readBebek(){
    cin >> N >> Q;
    for(int i=0;i<N;i++){
        cin >> bb[i];
    }
}

int caribatas(int a, int awal, int akhir){
    int tengah = (awal+akhir)/2;
    cout << "tengah:" << tengah;
    if(bb[tengah]==a){
        return tengah;
    } else if((bb[tengah]>a) &&(bb[tengah-1]<a)){
        return tengah;
    } else if(bb[tengah]>a){
        return caribatas(a,awal,tengah-1);
    } else {
        return caribatas(a,tengah+1,akhir);
    }
}

int caribebek(int a, int b){
    int c = caribatas(b, 0, N)-caribatas(a, 0, N);
    if(c>=0){
        return c;
    } else {
        return 0;
    }
}

int main(){
    readBebek();
    for(int i=0;i<Q;i++){
        cin >> batas[0] >> batas[1];
        cout << caribebek(batas[0],batas[1]) << endl;
    }
}