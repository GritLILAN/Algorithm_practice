#include<bits/stdc++.h>
using namespace std;

int a,b,c,k;

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> a >> b >> c >> k;
        while(k--){
            if(a == b && b == c) break;
            int ta = a, tb = b, tc = c;
            a = (tb + tc) / 2;
            b = (ta + tc) / 2;
            c = (ta + tb) / 2;
        }
        cout << a << ' ' << b << ' ' << c << endl;
    }

    return 0;
}