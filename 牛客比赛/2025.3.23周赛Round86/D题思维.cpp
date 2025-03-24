#include<bits/stdc++.h>
using namespace std;
//最多3步，x op y = z, x op y = z, z xor z = 0
//or只会变大，直接不考虑

int x, y;

int solve(){
    if((x & y) == 0 || (x ^ y) == 0) return 1;
    int XOR = x ^ y, AND = x & y, GCD = __gcd(x, y);
    if((x & XOR) == 0 || (y & XOR) == 0) return 2;
    if((x ^ AND) == 0 || (y ^ AND) == 0) return 2;
    if((x & GCD) == 0 || (y & GCD) == 0) return 2;
    if((x ^ GCD) == 0 || (y ^ GCD) == 0) return 2;
    return 3;
}

int main(){
    int t; cin >> t;
    while(t--){
        cin >> x >> y;
        cout << solve() << endl;
    }

    return 0;
}
