#include<bits/stdc++.h>
using namespace std;
const int N = 1010;

int n;
int odd = 0, even = 0;

int main(){
    cin >> n;
    while(n--){
        int a; cin >> a;

        if(a & 1) odd++;
        else even++;
    }

    cout << odd << ' ' << even << endl;

    return 0;
}