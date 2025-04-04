#include<bits/stdc++.h>
using namespace std;

int n;

bool check(int a){
    if(a == 1) return false;
    for(int i = 2; i < a / i; i++){
        if(a % i == 0) return false;
    }
    return true;
}

int main(){
    cin >> n;
    while(n--){
        int a; cin >> a;
        if(check(a)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }


    return 0;
}