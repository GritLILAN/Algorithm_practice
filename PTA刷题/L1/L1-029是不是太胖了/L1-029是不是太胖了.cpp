#include<bits/stdc++.h>
using namespace std;

int h;
double w;

int main(){

    cin >> h;
    w = (h - 100) * 0.9 * 2;

    cout << fixed << setprecision(1) << w << endl;

    return 0;
}