#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5;
const int mod = 1e9 + 7;

int n,m;
int v[N];
int fact[N], infact[N];
int res = 1;

int qpow(int a, int b, int p){
    int ans = 1;
    while(b){
        if(b & 1) ans = ans * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return ans;
}

void init(){//预处理阶乘（快速幂求逆元）
    fact[0] = infact[0] = 1;
    for(int i = 1; i < N; i++){
        fact[i] = fact[i - 1] * i % mod;
        infact[i] = qpow(fact[i], mod - 2, mod) % mod;
    }
}


signed main(){
    init();
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> v[i];
        int tmp = fact[v[i] + m] * infact[m] % mod;
        tmp = tmp * infact[v[i]] % mod;
        res = res * tmp % mod;
    }  

    cout << res << endl;


    return 0;
}