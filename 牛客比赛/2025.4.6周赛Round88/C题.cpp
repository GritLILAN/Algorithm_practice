#include<bits/stdc++.h>
using namespace std;

bool check(){
    double x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

        double midx1 = (x2 + x3) / 2;
        if(midx1 == x1) return true;
        double midy1 = (y2 + y3) / 2;
        if(midy1 == y1) return true;
        double midx2 = (x1 + x3) / 2;
        if(midx2 == x2) return true;
        double midy2 = (y1 + y3) / 2;
        if(midy2 == y2) return true;
        double midx3 = (x1 + x2) / 2;
        if(midx3 == x3) return true;
        double midy3 = (y1 + y2) / 2;
        if(midy3 == y3) return true;

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