#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;

int main(){
    char ch;
    ll f = 0, m = 0;//f是分子，m是分母
    cin >> n;
    cin >> f >> ch >> m;
    for(int i = 1; i < n; i++){
        ll a, b;
        cin >> a >> ch >> b;
        ll lcm = b * m / __gcd(b, m);
        f = lcm / m * f + lcm / b * a;
        m = lcm;
    }    

    if(f / m){
        cout << f /m;
    }
    if(f / m && f % m){
        cout << ' ';
    }
    if(f % m){
        f = f % m;
        ll gcd_fm = __gcd(f, m);
        cout << f / gcd_fm << '/' << m / gcd_fm << endl; 
    }
    if(!f){
        cout << 0 << endl;
    }


    return 0;
}