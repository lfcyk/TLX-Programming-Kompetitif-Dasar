#include<iostream>
#include<string>
using namespace std;

string key, a[101], prefix, postfix;
int N;



void readInput(){
    cin >> key;
    cin >> N;

    for(int i=0;i<N;i++){
        cin >> a[i];
    }
}

void writeOutput(string s){
    cout << s << endl;
}

void setSuffix(){
    bool afterAskterisk=false;
    for(int i=0;i<key.length();i++) {
        if(key[i]=='*'){
            afterAskterisk=true;
        }
        else if(afterAskterisk){
            postfix+= key[i];
        } else {
            prefix+= key[i];
        }
    }
}
bool isWildCard(string s){
    int i;
    for(i=0;i<prefix.length();i++){
        if(prefix[i]!=s[i]){
            return false;
        }
    }

    for(int j=0;j<postfix.length();j++){
        if(s.length()-1-j<i){
            return false;
        }
        if(postfix[postfix.length()-1-j]!=s[s.length()-1-j]){
            return false;
        }
    }
    return true;
}

int main(){
    readInput();
    setSuffix();
    for(int i=0;i<N;i++){
        if(isWildCard(a[i])){
            writeOutput(a[i]);
        }
    }
}