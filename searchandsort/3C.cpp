#include<iostream>
#include<string>
#define POPULATION 100000

using namespace std;

int N,Q;
string name[POPULATION], nomor[POPULATION], dpo[POPULATION];

void readtel(){
    cin >> N >> Q;
    for(int i=0;i<N;i++){
        cin >> name[i] >> nomor[i];
    }
    for(int i=0;i<Q;i++){
        cin >> dpo[i];
    }
}

bool adakahOrangIni(string a, int awal, int akhir){
    if(akhir>awal){
        return false;
    }
    if(a==name[(awal+akhir)/2]){
        cout << a << endl;
        return true;
    } else if(int(a[0])>int(name[0])){
        return adakahOrangIni(a,(awal+akhir)/2+1,akhir);
    } else if(int(a[0])<int(name[0])){
        return adakahOrangIni(a,awal,(awal+akhir)/2+1);
    } else {
        for(int i=1;i<a.length;i++){
            if(int(a[0])>int(name[0])){
                return adakahOrangIni(a,(awal+akhir)/2+1,akhir);
            } else if(int(a[0])<int(name[0])){
                return adakahOrangIni(a,awal,(awal+akhir)/2+1);
            }
        }
    }
    return false;
}

int main(){
    readtel();
    for(int i=0;i<Q;i++){
        if(!adakahOrangIni(dpo[i],0,N)){
            cout << "NIHIL" << endl;
        }
    }
}