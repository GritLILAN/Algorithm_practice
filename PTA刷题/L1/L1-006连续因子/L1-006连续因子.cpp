#include<bits/stdc++.h>
#define int long long
using namespace std;

int n;
int len = 0, res = 0;

int cal(int x){
    int num = 0, sum = n;
    for(int i = x; sum != 0; i++){
        if(sum % i == 0){
            sum /= i;
            num++;
        }
        else break;
    }
    return num;
}

signed main(){
    cin >> n;
    for(int i = 2; i <= n / i; i++){
        int tmplen = cal(i);
        if(tmplen > len){
            len = tmplen; res = i;
        }
    }

    if(!len){
        cout << 1 << endl;
        cout << n << endl; return 0;
    }

    cout << len << endl;
    for(int i = 0; i < len; i++){
        if(!i) cout << res + i;
        else cout << '*' << res + i;
    }

    return 0;
}