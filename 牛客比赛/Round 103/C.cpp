#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;

int n;

int qmi(int a, int b){
    int res = 1;
    while(b){
        if(b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

signed main(){
    cin >> n;

    int res = qmi(2, n - 1);

    cout << res << endl;

    return 0;
}