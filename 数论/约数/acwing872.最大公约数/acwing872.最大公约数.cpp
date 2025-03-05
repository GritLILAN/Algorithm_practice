#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int n;

int gcd(int a, int b){
    return b ? gcd(b, a % b) : a;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        int a,b;
        cin >> a >> b;
        cout << gcd(a,b) << endl;
    }

    return 0;
}