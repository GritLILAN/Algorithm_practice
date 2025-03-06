#include<bits/stdc++.h>
using namespace std;
int n;

long long qmi(long long a, int b, int p){//a要开long long
    long long res = 1;
    while(b > 0){
        if(b & 1) res = res * a % p;
        a = a * a % p;//不能写成a *= a % p;
        b >>= 1;
    }
    return res;
}

int main(){
    cin >> n;
    while(n--){
        int a, b, p;
        cin >> a >> b >> p;

        cout << qmi(a,b,p) << endl;
    }
    return 0;
}