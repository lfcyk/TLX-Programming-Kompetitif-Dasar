#include<iostream>
using namespace std;

string a,b;

void readS(){
    cin >> a;
    cin >> b;
}

void writeyes(){
    cout << "Tentu saja bisa!" << endl;
}

void writeno(){
    cout << "Wah, tidak bisa :(" << endl;
}

bool bisatidakyah(string a, string b){
    int skip=0;
    for(int i=0;i<a.length();i++){
        if(a[i]!=b[i-skip]){
            if(skip>=1){
                return false;
            } else {
                skip=1;
            }
        }
    }
    return true;
}

int main(){
    readS();
    if(a.length() - b.length() == 1){
        if(bisatidakyah(a,b)){
            writeyes();
        } else {
            writeno();
        }
    } else {
        writeno();
    }
}