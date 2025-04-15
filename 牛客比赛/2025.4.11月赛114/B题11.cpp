#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N = 1e5 + 5;

int n;
int a[N];
int res = 0;
bool st[N];


signed main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i] <= n && !st[a[i]]) res += a[i];
        st[a[i]] = true;
    }

    cout << res << endl;


    return 0;
}