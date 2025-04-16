#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;

int qmi(int a, int b){
    int res = 1;
    while(b){
        if(b & 1){
            res = res * a % mod;
        }
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

signed main(){
    // for(int i = 1; i <= 2025; i++){
    //     cout << i << ' ';
    //     cout << fixed << setprecision(10) << double(sqrt(i * i + 2025)) << endl;
    // }

    cout << qmi(2, 1012) << endl;
    

    return 0;
}