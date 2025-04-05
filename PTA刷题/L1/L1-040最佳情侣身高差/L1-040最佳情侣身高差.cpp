#include<bits/stdc++.h>
using namespace std;


int main(){
    int t; cin >> t;
    while(t--){
        char gen; cin >> gen;
        double h; cin >> h;
        double res;
        if(gen == 'M') res = h /1.09;
        if(gen == 'F') res = h * 1.09;

        cout << fixed << setprecision(2) << res << endl;
    }

    return 0;
}