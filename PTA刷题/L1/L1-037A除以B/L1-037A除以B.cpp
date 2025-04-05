#include<bits/stdc++.h>
using namespace std;


int main(){
    int a, b;
    cin >> a >> b;
    double res = (double)a / b;

    char ch = '/';
    cout << a;
    cout << ch;
    if(b < 0) cout << '(' << b << ')';
    else cout << b;
    if(!b) cout << "=Error" << endl;
    else cout << '=' << fixed << setprecision(2) << res << endl;

    return 0;
}