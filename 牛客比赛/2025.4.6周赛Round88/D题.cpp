#include<bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin >> t;
    while(t--){
        int x; cin >> x;
        int z = 0;
        int base = 1;
        while(x){
            int u = !(x & 1);
            z += u * base;
            base *= 2;
            x >>= 1;
            if(!x) break;
        }
        cout << z << endl;
    }


    return 0;
}