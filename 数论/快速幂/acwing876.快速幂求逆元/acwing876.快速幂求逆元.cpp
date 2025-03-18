#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int qpow(int a, int b, int p){
    int ans = 1;
    while(b){
        if(b & 1) ans = 1ll * ans * a % p;
        a = 1ll * a * a % p;
        b >>= 1;
    }
    return ans;
}


int main(){
    int t; cin >> t;
    while(t--){
        int a, p;
        cin >> a >> p;
        if(a % p == 0) puts("impossible");
        else{
            int res = qpow(a, p - 2, p);
            cout << res << endl;
        }
    }

    return 0;
}