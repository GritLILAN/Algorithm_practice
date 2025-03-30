#include<bits/stdc++.h>
using namespace std;

int n;

int main(){
    cin >> n;
    int sum = 0;
    int last = 1;
    for(int i = 1; i <= n; i++){
        last *= i;
        sum += last;
    }

    cout << sum << endl;

    return 0;
}