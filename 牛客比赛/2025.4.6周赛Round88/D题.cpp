#include<bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin >> t;
    while(t--){
        int x; cin >> x;
        int z = 0;
        int base = 1;
        bool f = false;
        while(x){
            int u = !(x & 1);
            if(u) f = true;
            z += u * base;
            base *= 2;
            x >>= 1;
            if(!x) break;
        }
        if(!f) cout << -1 << endl;
        else cout << z << endl;
    }


    return 0;
}