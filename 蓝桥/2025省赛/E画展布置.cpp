#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5;

int n, m;
int a[N];
int s[N];
int  res = LLONG_MAX;

signed main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        a[i] *= a[i];
    } 
    sort(a + 1, a + 1 + n);
    
    for(int i = 1; i <= n - m + 1; i++){
        res = min(res, a[i + m - 1] - a[i]);
    }

    cout << res << endl;
    return 0;
}