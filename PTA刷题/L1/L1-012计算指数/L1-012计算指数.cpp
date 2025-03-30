#include<bits/stdc++.h>
using namespace std;

int n;

int main(){
    cin >> n;
    long long res = 1;
    for(int i = 0; i < n; i++){
        res *= 2;
    }

    cout << "2^" << n << " = " << res << endl;

    return 0;
}