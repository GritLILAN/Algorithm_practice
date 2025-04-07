#include<bits/stdc++.h>
using namespace std;

bool check(){
    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    if((x2 + x3) % 2 != 0){
        int midx = (x2 + x3) / 2;
        if(midx == x1) return true;
    }
    if((y2 + y3) % 2 != 0){
        int midy = (y2 + y3) / 2;
        if(midy == y1) return true;
    }
    if((x1 + x3) % 2 != 0){
        int midx = (x1 + x3) / 2;
        if(midx == x2) return true;
    }
    if((y1 + y3) % 2 != 0){
        int midy = (y1 + y3) / 2;
        if(midy == y2) return true;
    }
    if((x1 + x2) % 2 != 0){
        int midx = (x1 + x2) / 2;
        if(midx == x3) return true;
    }
    if((y1 + y3) % 2 != 0){
        int midy = (y1 + y3) / 2;
        if(midy == y3) return true;
    }

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