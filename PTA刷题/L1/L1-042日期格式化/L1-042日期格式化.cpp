#include<bits/stdc++.h>
using namespace std;


int main(){
    string y, m, d;
    string s;
    cin >> s;
    m = s.substr(0, 2);
    d = s.substr(3, 2);
    y = s.substr(6, 4);

    char c = '-';
    cout << y << c << m << c << d << endl;


    return 0;
}