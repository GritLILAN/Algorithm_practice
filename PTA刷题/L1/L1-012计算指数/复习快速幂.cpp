#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;

ll qmi(int a, int b){
    ll ans = 1;
    while(b){
        if(b & 1) ans *= a;
        a *= a;
        b >>= 1; 
    }
    return ans;
}

int main(){
    cin >> n;
    ll res = qmi(2, n);

    cout << "2^" << n << " = " <<  res << endl;

    return 0;
}