#include<iostream>
using namespace std;

long long E,F;

int gcd(long a, long b){
    if(b == 0){
        return a;
    } else {
        return gcd(b,a%b);
    }
}

int main(){
    long long A,B,C,D;
    cin >> A >> B;
    cin >> C >> D;

    E = A*D+C*B;
    F = B*D;

    long long n = gcd(E,F);

    cout << E/n << " " << F/n;
}