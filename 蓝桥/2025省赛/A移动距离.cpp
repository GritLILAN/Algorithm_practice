#include<bits/stdc++.h>
using namespace std;

int main(){
    double x = 233, y = 666;
    double r = sqrt(x * x + y * y);
    double l = atan2(y, x);

    int res = round(r + r * l);
    cout << res << endl;

    //答案1576
    return 0;
}
