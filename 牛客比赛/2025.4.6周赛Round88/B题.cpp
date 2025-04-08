#include<bits/stdc++.h>
using namespace std;

bool check(){
    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    if(x1 == 0 && (x2 + x3) == 0) return true;
    if(y1 == 0 && (y2 + y3) == 0) return true;
    if(x2 == 0 && (x1 + x3) == 0) return true;
    if(y2 == 0 && (y1 + y3) == 0) return true;
    if(x3 == 0 && (x1 + x2) == 0) return true;
    if(y3 == 0 && (y1 + y2) == 0) return true;

    return false;

}


int main(){
    int t; cin >> t;
    while(t--){
        if(check()){
            cout << "Yes" << endl;
        }
        else cout << "No" << endl;
    }

    return 0;
}

