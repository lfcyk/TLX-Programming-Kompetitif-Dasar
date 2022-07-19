#include<iostream>
#include<math.h>
#define maxn 10000000

using namespace std;

long long T,K[20000],primes[maxn];
bool P[maxn];
long long nthprime;

void sieve(){
    for(int i=2;i*i<maxn;i++){
        if(P[i]==true){
            for(int j=i;i*j<maxn;j++){
                P[i*j]=false;
            }
        }
    }
}

int main(){
    cin >> T;

    for(int i=0;i<T;i++){
        cin >> K[i];
    }
    
    for(int j=2;j<=maxn;j++){
        P[j]=true;
    }

    sieve();
    
    int i=1;
    for(int j=2;j<=maxn;j++){
        if(P[j]){
            primes[i]=j;
            i++;
        }
    }

    for(int i=0;i<T;i++){
        cout << primes[K[i]] << endl;
    }
}