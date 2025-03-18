#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
const int mod = 1e9 + 7;

int fact[N], infact[N];//阶乘和阶乘的逆元

int qpow(int a, int b, int p){
    int ans = 1;
    while(b){
        if(b & 1) ans = 1ll * ans * a % p;
        b >>= 1;
        a = 1ll * a * a % mod;
    }
    return ans;
}

void init(){
    fact[0] = infact[0] = 1;
    for(int i = 1; i < N; i++){
        fact[i] = (ll)fact[i - 1] * i % mod;
        infact[i] = (ll)qpow(fact[i], mod - 2, mod) % mod;
    }
}

int main(){
    init();
    int t; cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        int res = (ll)fact[a] * infact[b] % mod * infact[a - b] % mod;
        cout << res << endl;
    }


    return 0;
}