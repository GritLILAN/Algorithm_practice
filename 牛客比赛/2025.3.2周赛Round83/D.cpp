#include<bits/stdc++.h>
#define int long long
using namespace std;

int x, y;

void solve(int t){
    if(t == 1){
        x = 0, y = 0; return;
    }

    int n = ceil(sqrt(t));
    if(n % 2 == 0) n += 1;
    int tmp = n * n - t;

    if(tmp < n){//上边
        y = n / 2;
        x = n / 2 - tmp;
    }
    else if(tmp < 2 * n - 1){//左边
        tmp -= n;
        x = -(n / 2);
        y = (n / 2 - 1) - tmp;
    }
    else if(tmp < 3 * n - 2){//下边
        tmp -= 2 * n - 1;
        y = -(n / 2);
        x = -(n / 2 - 1) + tmp;
    }
    else{//右边
        int base = (n - 2) * (n - 2);
        tmp = t - base;
        x = n / 2;
        y = n / 2 - tmp;
    }

}


signed main(){
    int T;
    cin >> T;
    while(T--){
        int t;
        cin >> t;

        solve(t);
        cout << x << ' ' << y << endl;
    }


    return 0;
}