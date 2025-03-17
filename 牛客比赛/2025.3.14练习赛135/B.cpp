#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5;

int n, m, q;
int a[N];


signed main(){
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    
    int res = m % 2;
    while(q--){
        int l, r;
        cin >> l >> r;
        if(l != r) res ^= 1;
        cout << (res ? "odd" : "even") << endl;
    }


    return 0;
}