#include<bits/stdc++.h>
using namespace std;


int main(){
    int n, m = 1, f = 1;
    char c;
    cin >> n >> c;

    for(int i = 3; ; i += 2){
        if(m + i * 2 > n) break;
        m += i * 2;
        f = i;
    }

    for(int i = f; i >= 1; i -= 2){
        for(int j = 0; j < (f - i) / 2; j++) cout << ' ';
        for(int j = 0; j < i; j++) cout << c;
        cout << endl;
    }
    for(int i = 3; i <= f; i += 2){
        for(int j = 0; j < (f - i) /2; j++) cout << ' ';
        for(int j = 0; j < i; j++) cout << c;
        cout << endl;
    }
    cout << n - m << endl;


    return 0;
}