#include<bits/stdc++.h>
#define int long long
using namespace std;

int a[4];
int res = 0;

int check(){
    if(a[0] == a[1] && a[1] == a[2] && a[2] == a[3]) return 1;
    if(a[1] == a[2] && a[2] == a[3]) return 1;
    if(a[0] == a[1] && a[1] == a[2]) return 2;
    return 0;
}

signed main(){
    for(int i = 0; i < 4; i++) cin >> a[i];
    sort(a, a + 4);

    if(check() == 1){
        res += a[0];
        res += 2 * a[3];
    }
    else if(check() == 2){
        res += a[3];
        res += 2 * a[0];
    }
    else{
        a[3] += a[0] * 2;
        res += a[3];
        a[1] -= a[0];
        res += a[1]/3 * 3;
        if(a[1] % 3 == 2) res++;
    }

    cout << res << endl;


    return 0;
}