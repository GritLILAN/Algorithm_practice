#include<bits/stdc++.h>
using namespace std;



int main(){
    int d;
    cin >> d;
    
    int res = (d + 2) % 7;
    if(!res) res = 7;

    cout << res << endl;


    return 0;
}